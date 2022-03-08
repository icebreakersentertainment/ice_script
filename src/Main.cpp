#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <limits>

#ifdef WIN32
#define NOMINMAX
#undef min
#undef max
#endif

#include <llvm/ADT/APFloat.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Constants.h>
#include <llvm/IR/DerivedTypes.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Verifier.h>

using namespace llvm;

//std::unique_ptr<FunctionAST> ParseDefinition(LLVMContext& context, Module& module, IRBuilder<>& builder, std::map<std::string, Value*>& namedValues)
//{
//    Function *TheFunction = module.getFunction(Proto->getName());
//
//    if (!TheFunction)
//        TheFunction = Proto->codegen();
//
//    if (!TheFunction)
//        return nullptr;
//
//    // Create a new basic block to start insertion into.
//    BasicBlock* BB = BasicBlock::Create(context, "entry", TheFunction);
//    builder.SetInsertPoint(BB);
//
//    // Record the function arguments in the namedValues map.
//    namedValues.clear();
//    for (auto &Arg : TheFunction->args())
//    {
//        namedValues[std::string(Arg.getName())] = &Arg;
//    }
//
//    if (Value *RetVal = Body->codegen()) {
//        // Finish off the function.
//        builder.CreateRet(RetVal);
//
//        // Validate the generated code, checking for consistency.
//        verifyFunction(*TheFunction);
//
//        return TheFunction;
//    }
//
//    // Error reading body, remove function.
//    TheFunction->eraseFromParent();
//    return nullptr;
//}

int main()
{
    std::unique_ptr<LLVMContext> context;
    std::unique_ptr<Module> module;
    std::unique_ptr<IRBuilder<>> builder;
    std::map<std::string, Value*> namedValues;

    context = std::make_unique<LLVMContext>();
    module = std::make_unique<Module>("my cool jit", *context);
    builder = std::make_unique<IRBuilder<>>(*context);

    std::cout << "Generating" << std::endl;
    std::cout << std::endl;

    Function* testFunction;
    {
        // Make the function type:  int(int, int) etc.
        std::vector<Type*> integers{2, Type::getInt64Ty(*context)};
        FunctionType* FT = FunctionType::get(Type::getInt64Ty(*context), integers, false);

        testFunction = Function::Create(FT, Function::ExternalLinkage, "test", module.get());

        // Set names for all arguments.
//    unsigned Idx = 0;
//    for (auto &Arg : F->args())
//        Arg.setName(Args[Idx++]);
//
//    return F;

//    namedValues.clear();
//    for (auto &Arg : F->args())
//    {
//        std::cout << "ARG " << Arg.getArgNo() << ": " << std::string(Arg.getName()) << std::endl;
//        namedValues[std::string(Arg.getName())] = &Arg;
//    }

        BasicBlock* BB = BasicBlock::Create(*context, "entry", testFunction);
        builder->SetInsertPoint(BB);

//    llvm::APFlo
//    Value* constant = ConstantFP::get(*context, llvm::APInt(1));

//    auto it = namedValues.begin();
        auto itr = testFunction->args();
        auto it = itr.begin();
        Value* L = (Value*) &(*it);
        Value* R = (Value*) &(*(++it));
        Value* result = builder->CreateAdd(L, R, "addtmp");
        builder->CreateRet(result);
    }
//    define i32 @main() {
//        entry:
//        %0 = call i32 @mul(i32 1, i32 2)
//        ; call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @formatString , i32 0, i32 0), i32 %0)
//        %ptr = getelementptr inbounds [5 x i8], [5 x i8]* @formatString , i32 0, i32 0
//                                                                                     %testStringPtr = getelementptr inbounds [5 x i8], [5 x i8]* @testString , i32 0, i32 0
//        call i32 (i8*, ...) @printf(i8* %ptr, i32 %0)
//        call i32 (i8*) @puts(i8* %testStringPtr)
//        ret i32 1
//    }

    {
        FunctionType* FT = FunctionType::get(Type::getInt64Ty(*context), {}, false);

        Function* F = Function::Create(FT, Function::ExternalLinkage, "main", module.get());

        BasicBlock* BB = BasicBlock::Create(*context, "entry", F);
        builder->SetInsertPoint(BB);

        std::vector<Value*> ArgsV;

        Value* constant1 = ConstantInt::get(IntegerType::getInt64Ty(*context), 1);
        Value* constant2 = ConstantInt::get(IntegerType::getInt64Ty(*context), 1);
        ArgsV.push_back(constant1);
        ArgsV.push_back(constant2);

        Value* result = builder->CreateCall(testFunction, ArgsV, "calltmp");

//        auto itr = F->args();
//        auto it = itr.begin();
//        Value* L = (Value*) &(*it);
//        Value* R = (Value*) &(*(++it));
//        Value* result = builder->CreateFAdd(L, R, "addtmp");
        builder->CreateRet(result);
    }

    std::cout << "Printing" << std::endl;
    std::cout << std::endl;

    module->print(errs(), nullptr);

    std::cout << std::endl;
    std::cout << "Done" << std::endl;

    return 0;
}