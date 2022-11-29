#include <llvm/Support/MemoryBuffer.h>

#include "llvm/CodeGen/CommandFlags.h"
#include "llvm/CodeGen/LinkAllCodegenComponents.h"
#include "llvm/ExecutionEngine/ObjectCache.h"
#include <llvm/ExecutionEngine/Orc/DebugObjectManagerPlugin.h>
#include <llvm/ExecutionEngine/Orc/DebugUtils.h>
#include <llvm/ExecutionEngine/Orc/EPCDebugObjectRegistrar.h>
#include <llvm/ExecutionEngine/Orc/EPCEHFrameRegistrar.h>
#include <llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include <llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h>
#include <llvm/ExecutionEngine/Orc/LLJIT.h>
#include <llvm/ExecutionEngine/Orc/OrcRemoteTargetClient.h>
#include <llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include <llvm/ExecutionEngine/Orc/SymbolStringPool.h>
#include <llvm/ExecutionEngine/Orc/TargetProcess/JITLoaderGDB.h>
#include <llvm/ExecutionEngine/Orc/TargetProcess/RegisterEHFrames.h>
#include <llvm/ExecutionEngine/Orc/TargetProcess/TargetExecutionUtils.h>
#include <llvm/ExecutionEngine/SectionMemoryManager.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Object/Archive.h>
#include <llvm/Object/ObjectFile.h>
#include <llvm/Support/CommandLine.h>
#include <llvm/Support/Debug.h>
#include <llvm/Support/DynamicLibrary.h>
#include <llvm/Support/Format.h>
#include <llvm/Support/InitLLVM.h>
#include <llvm/Support/ManagedStatic.h>
#include <llvm/Support/MathExtras.h>
#include <llvm/Support/Memory.h>
#include <llvm/Support/MemoryBuffer.h>
#include <llvm/Support/Path.h>
#include <llvm/Support/PluginLoader.h>
#include <llvm/Support/Process.h>
#include <llvm/Support/Program.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Support/WithColor.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Transforms/Instrumentation.h>

#include "engine/llvm/LlvmOrcJit.hpp"

#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace engine { namespace llvm {

using namespace ::llvm;

static codegen::RegisterCodeGenFlags CGF;

static void exitOnLazyCallThroughFailure()
{
    exit(1);
}

static std::function<void(Module&)> createDebugDumper() {
//  switch (OrcDumpKind) {
//  case DumpKind::NoDump:
    return [](Module &M) {};
//
//  case DumpKind::DumpFuncsToStdOut:
//    return [](Module &M) {
//      printf("[ ");
//
//      for (const auto &F : M) {
//        if (F.isDeclaration())
//          continue;
//
//        if (F.hasName()) {
//          std::string Name(std::string(F.getName()));
//          printf("%s ", Name.c_str());
//        } else
//          printf("<anon> ");
//      }
//
//      printf("]\n");
//    };
//
//  case DumpKind::DumpModsToStdOut:
//    return [](Module &M) {
//      outs() << "----- Module Start -----\n" << M << "----- Module End -----\n";
//    };
//
//  case DumpKind::DumpModsToDisk:
//    return [](Module &M) {
//      std::error_code EC;
//      raw_fd_ostream Out(M.getModuleIdentifier() + ".ll", EC,
//                         sys::fs::OF_TextWithCRLF);
//      if (EC) {
//        errs() << "Couldn't open " << M.getModuleIdentifier()
//               << " for dumping.\nError:" << EC.message() << "\n";
//        exit(1);
//      }
//      Out << M;
//    };
//  }
//  llvm_unreachable("Unknown DumpKind");
}

std::string toString(const SMDiagnostic& smDiagnostic)
{
    std::string errorMessage;

    raw_string_ostream rawStringOstream(errorMessage);
    smDiagnostic.print("lli", rawStringOstream);

    return errorMessage;
}

void LlvmOrcJit::execute(const std::string& script)
{
//    InitLLVM X(argc, argv);

    // If we have a native target, initialize it to ensure it is linked in and
    // usable by the JIT.
    InitializeNativeTarget();
    InitializeNativeTargetAsmPrinter();
    InitializeNativeTargetAsmParser();

    // If the user doesn't want core files, disable them.
//    if (DisableCoreFiles)
        sys::Process::PreventCoreFiles();

//    ExitOnErr(loadDylibs());

    std::string entryFunc = "main";

    orc::ThreadSafeContext threadSafeContext{std::make_unique<LLVMContext>()};

    auto memoryBuffer = MemoryBuffer::getMemBuffer(script);

    SMDiagnostic smDiagnostic{};
    auto module = parseIR(*memoryBuffer, smDiagnostic, *threadSafeContext.getContext());
    if (!module) throw RuntimeException(toString(smDiagnostic));

    orc::ThreadSafeModule threadSafeModule{std::move(module), std::move(threadSafeContext)};

    // Get TargetTriple and DataLayout from the main module if they're explicitly
    // set.
    Optional<Triple> targetTriple;
    Optional<DataLayout> dataLayout;
    threadSafeModule.withModuleDo([&](Module &_module) {
        if (!_module.getTargetTriple().empty()) targetTriple = Triple(_module.getTargetTriple());
        if (!_module.getDataLayout().isDefault()) dataLayout = _module.getDataLayout();
    });

    orc::LLLazyJITBuilder builder;

    if (targetTriple)
    {
        builder.setJITTargetMachineBuilder(orc::JITTargetMachineBuilder(*targetTriple));
    }
    else
    {
        auto jitTargetMachineBuilder = orc::JITTargetMachineBuilder::detectHost();
        if (!jitTargetMachineBuilder) throw RuntimeException(toString(jitTargetMachineBuilder.takeError()));

        builder.setJITTargetMachineBuilder(jitTargetMachineBuilder.get());
    }

    targetTriple = builder.getJITTargetMachineBuilder()->getTargetTriple();
    if (dataLayout) builder.setDataLayout(dataLayout);

    if (!codegen::getMArch().empty())
    {
        builder.getJITTargetMachineBuilder()->getTargetTriple().setArchName(codegen::getMArch());
    }

    builder.getJITTargetMachineBuilder()->setCPU(codegen::getCPUStr())
            .addFeatures(codegen::getFeatureList())
            .setRelocationModel(codegen::getExplicitRelocModel())
            .setCodeModel(codegen::getExplicitCodeModel());

    // FIXME: Setting a dummy call-through manager in non-lazy mode prevents the
    // JIT builder to instantiate a default (which would fail with an error for
    // unsupported architectures).
//    if (UseJITKind != JITKind::OrcLazy)
//    {
        auto selfExecutorProcessControl = orc::SelfExecutorProcessControl::Create();
        if (!selfExecutorProcessControl) throw RuntimeException(toString(selfExecutorProcessControl.takeError()));
        auto executionSession = std::make_unique<orc::ExecutionSession>(std::move(selfExecutorProcessControl.get()));
        builder.setLazyCallthroughManager(std::make_unique<orc::LazyCallThroughManager>(*executionSession, 0, nullptr));
        builder.setExecutionSession(std::move(executionSession));
//    }

    builder.setLazyCompileFailureAddr(pointerToJITTargetAddress(exitOnLazyCallThroughFailure));
    builder.setNumCompileThreads(0);

    // If the object cache is enabled then set a custom compile function
    // creator to use the cache.
//    std::unique_ptr<LLIObjectCache> cacheManager;
//    if (EnableCacheManager)
//    {
//
//        cacheManager = std::make_unique<LLIObjectCache>(ObjectCacheDir);
//
//        Builder.setCompileFunctionCreator(
//                [&](orc::JITTargetMachineBuilder JTMB)
//                        -> Expected <std::unique_ptr<orc::IRCompileLayer::IRCompiler>> {
//                    if (LazyJITCompileThreads > 0)
//                        return std::make_unique<orc::ConcurrentIRCompiler>(std::move(JTMB),
//                                                                           cacheManager.get());
//
//                    auto TM = JTMB.createTargetMachine();
//                    if (!TM)
//                        return TM.takeError();
//
//                    return std::make_unique<orc::TMOwningSimpleCompiler>(std::move(*TM),
//                                                                         cacheManager.get());
//                });
//    }

    // Set up LLJIT platform.
//    {
//        LLJITPlatform P = Platform;
//        if (P == LLJITPlatform::DetectHost)
//            P = LLJITPlatform::GenericIR;
//
//        switch (P)
//        {
//            case LLJITPlatform::GenericIR:
//                // Nothing to do: LLJITBuilder will use this by default.
//                break;
//            case LLJITPlatform::Inactive:
//                Builder.setPlatformSetUp(orc::setUpInactivePlatform);
//                break;
//            default:
//                llvm_unreachable("Unrecognized platform value");
//        }
//    }

    std::unique_ptr<orc::ExecutorProcessControl> executorProcessControl = nullptr;
//    if (JITLinker == JITLinkerKind::JITLink)
//    {
//        executorProcessControl = ExitOnErr(orc::SelfExecutorProcessControl::Create(
//                std::make_shared<orc::SymbolStringPool>()));
//
//        Builder.setObjectLinkingLayerCreator([&executorProcessControl](orc::ExecutionSession& ES,
//                                                                       const Triple&) {
//            auto L = std::make_unique<orc::ObjectLinkingLayer>(ES, executorProcessControl->getMemMgr());
//            L->addPlugin(std::make_unique<orc::EHFrameRegistrationPlugin>(
//                    ES, ExitOnErr(orc::EPCEHFrameRegistrar::Create(ES))));
//            L->addPlugin(std::make_unique<orc::DebugObjectManagerPlugin>(
//                    ES, ExitOnErr(orc::createJITLoaderGDBRegistrar(ES))));
//            return L;
//        });
//    }

    auto jitTypeExpected = builder.create();
    if (!jitTypeExpected) throw RuntimeException(toString(jitTypeExpected.takeError()));
    auto jitType = std::move(jitTypeExpected.get());

    auto* ObjLayer = &jitType->getObjLinkingLayer();
    if (auto* RTDyldObjLayer = dyn_cast<orc::RTDyldObjectLinkingLayer>(ObjLayer))
    {
        std::cout << "DBG" << std::endl;
        RTDyldObjLayer->registerJITEventListener(*JITEventListener::createGDBRegistrationListener());
    }

//    if (PerModuleLazy)
//        jitType->setPartitionFunction(orc::CompileOnDemandLayer::compileWholeModule);

    auto dump = createDebugDumper();

    jitType->getIRTransformLayer().setTransform(
            [&](orc::ThreadSafeModule _threadSafeModule,
                const orc::MaterializationResponsibility& materializationResponsibility) {
                _threadSafeModule.withModuleDo([&](Module& _module) {
                    if (verifyModule(_module, &dbgs()))
                    {
                        dbgs() << "Bad module: " << &_module << "\n";
                        exit(1);
                    }
                    dump(_module);
                });
                return _threadSafeModule;
            });

    orc::MangleAndInterner mangle(jitType->getExecutionSession(), jitType->getDataLayout());

    // Unless they've been explicitly disabled, make process symbols available to
    // JIT'd code.
//  if (!NoProcessSymbols)
//  {
    auto dynamicLibrarySearchGenerator = orc::DynamicLibrarySearchGenerator::GetForCurrentProcess(
                      jitType->getDataLayout().getGlobalPrefix(),
                      [mainName = mangle("main")](const orc::SymbolStringPtr& symbolName) {
                          return symbolName != mainName;
                      });
    if (!dynamicLibrarySearchGenerator) throw RuntimeException(toString(dynamicLibrarySearchGenerator.takeError()));

    jitType->getMainJITDylib().addGenerator(std::move(dynamicLibrarySearchGenerator.get()));
//  }

//    if (GenerateBuiltinFunctions.size() > 0)
//        jitType->getMainJITDylib().addGenerator(
//                std::make_unique<LLIBuiltinFunctionGenerator>(GenerateBuiltinFunctions,
//                                                              mangle));

//    auto result = jitType->getMainJITDylib().define(
//            llvm::orc::absoluteSymbols({
//                   {mangle("malloc"),                 JITEvaluatedSymbol(
//                           pointerToJITTargetAddress((void*) (&malloc)),
//                           JITSymbolFlags::Exported)},
//                   {mangle("test"),                   JITEvaluatedSymbol(
//                           pointerToJITTargetAddress(&test), JITSymbolFlags::Exported)},
//                   {mangle("testDefaultConstructor"), JITEvaluatedSymbol(
//                           pointerToJITTargetAddress(&testDefaultConstructor),
//                           JITSymbolFlags::Exported)},
//                   {mangle("test_test"),              JITEvaluatedSymbol(
//                           pointerToJITTargetAddress(&test_test),
//                           JITSymbolFlags::Exported)},
//                   {mangle("test_a"),                 JITEvaluatedSymbol(
//                           pointerToJITTargetAddress(&test_a), JITSymbolFlags::Exported)},
//                   {mangle("test_mangle"),            JITEvaluatedSymbol(
//                           pointerToJITTargetAddress(&test_mangle),
//                           JITSymbolFlags::Exported)},
//           })
//    );
//
//    if (result)
//    {
//        return errorToErrorCode(std::move(result)).value();
//    }

    // Regular modules are greedy: They materialize as a whole and trigger
    // materialization for all required symbols recursively. Lazy modules go
    // through partitioning and they replace outgoing calls with reexport stubs
    // that resolve on call-through.
//    auto AddModule = [&](orc::JITDylib& JD, orc::ThreadSafeModule M) {
//        return UseJITKind == JITKind::OrcLazy ? jitType->addLazyIRModule(JD, std::move(M))
//                                              : jitType->addIRModule(JD, std::move(M));
//    };

    auto addModule = [&](orc::JITDylib& jitDylib, orc::ThreadSafeModule _threadSafeModule) {
        return jitType->addIRModule(jitDylib, std::move(_threadSafeModule));
    };

    // Add the main module.
    if (auto error = addModule(jitType->getMainJITDylib(), std::move(threadSafeModule)))
    {
        throw RuntimeException(toString(std::move(error)));
    }

    // Create JITDylibs and add any extra modules.
//    {
//        // Create JITDylibs, keep a map from argument index to dylib. We will use
//        // -extra-module argument indexes to determine what dylib to use for each
//        // -extra-module.
//        std::map<unsigned, orc::JITDylib*> IdxToDylib;
//        IdxToDylib[0] = &jitType->getMainJITDylib();
//        for (auto JDItr = JITDylibs.begin(), JDEnd = JITDylibs.end();
//             JDItr != JDEnd; ++JDItr)
//        {
//            orc::JITDylib* JD = jitType->getJITDylibByName(*JDItr);
//
//            if (!JD)
//            {
//                JD = &ExitOnErr(jitType->createJITDylib(*JDItr));
//                jitType->getMainJITDylib().addToLinkOrder(*JD);
//                JD->addToLinkOrder(jitType->getMainJITDylib());
//                JD->addToLinkOrder(jitType->getMainJITDylib());
//            }
//            IdxToDylib[JITDylibs.getPosition(JDItr - JITDylibs.begin())] = JD;
//        }
//
//        for (auto EMItr = ExtraModules.begin(), EMEnd = ExtraModules.end();
//             EMItr != EMEnd; ++EMItr)
//        {
//            auto M = ExitOnErr(loadModule(*EMItr, TSCtx));
//
//            auto EMIdx = ExtraModules.getPosition(EMItr - ExtraModules.begin());
//            assert(EMIdx != 0 && "ExtraModule should have index > 0");
//            auto JDItr = std::prev(IdxToDylib.lower_bound(EMIdx));
//            auto& JD = *JDItr->second;
//            ExitOnErr(addModule(JD, std::move(M)));
//        }
//
//        for (auto EAItr = ExtraArchives.begin(), EAEnd = ExtraArchives.end();
//             EAItr != EAEnd; ++EAItr)
//        {
//            auto EAIdx = ExtraArchives.getPosition(EAItr - ExtraArchives.begin());
//            assert(EAIdx != 0 && "ExtraArchive should have index > 0");
//            auto JDItr = std::prev(IdxToDylib.lower_bound(EAIdx));
//            auto& JD = *JDItr->second;
//            JD.addGenerator(ExitOnErr(orc::StaticLibraryDefinitionGenerator::Load(
//                    jitType->getObjLinkingLayer(), EAItr->c_str(), *targetTriple)));
//        }
//    }

    // Add the objects.
//    for (auto& ObjPath: ExtraObjects)
//    {
//        auto Obj = ExitOnErr(errorOrToExpected(MemoryBuffer::getFile(ObjPath)));
//        ExitOnErr(jitType->addObjectFile(std::move(Obj)));
//    }

    // Run any static constructors.
    if (auto error = jitType->initialize(jitType->getMainJITDylib()))
    {
         throw RuntimeException(toString(std::move(error)));
    }

    // Run any -thread-entry points.
    std::vector<std::thread> AltEntryThreads;
//    for (auto& ThreadEntryPoint: ThreadEntryPoints)
//    {
//        auto EntryPointSym = ExitOnErr(jitType->lookup(ThreadEntryPoint));
//        typedef void (* EntryPointPtr)();
//        auto EntryPoint =
//                reinterpret_cast<EntryPointPtr>(static_cast<uintptr_t>(EntryPointSym.getAddress()));
//        AltEntryThreads.push_back(std::thread([EntryPoint]() { EntryPoint(); }));
//    }

//    std::cout << "Connect gdb and press enter" << std::endl;
//    std::cin.ignore();

//  JITEvaluatedSymbol TestIrFuncSym = ExitOnErr(J->lookup("test_ir_func"));
//    using TestIrFuncTy = int();
//    auto TestIrFuncFn = jitTargetAddressToFunction<TestIrFuncTy *>(TestIrFuncSym.getAddress());
////    Result = orc::runAsMain(TestIrFuncFn, InputArgv, StringRef(InputFile));
//    int a = TestIrFuncFn();
//    std::cout << "WHOA: " << a << std::endl;

    // Resolve and run the main function.
    auto mainSymExpected = jitType->lookup(entryFunc);
    if (!mainSymExpected) throw RuntimeException(toString(mainSymExpected.takeError()));
    JITEvaluatedSymbol mainSymbol = mainSymExpected.get();
//    int Result;

//    if (executorProcessControl)
//    {
//        // ExecutorProcessControl-based execution with JITLink.
//        Result = ExitOnErr(executorProcessControl->runAsMain(mainSymbol.getAddress(), InputArgv));
//    }
//    else
//    {

        // Manual in-process execution with RuntimeDyld.
        using MainFunctionType = int(int, char* []);
        auto mainFunction = jitTargetAddressToFunction<MainFunctionType*>(mainSymbol.getAddress());
//        Result = orc::runAsMain(MainFn, InputArgv, StringRef(InputFile));
        int result = orc::runAsMain(mainFunction, {}, {});
        std::cout << "result: " << result << std::endl;
//    }

    // Wait for -entry-point threads.
//    for (auto& AltEntryThread: AltEntryThreads)
//        AltEntryThread.join();

    // Run destructors.
    if (auto error = jitType->deinitialize(jitType->getMainJITDylib()))
    {
        throw RuntimeException(toString(std::move(error)));
    }

//    return result;
}

}}}