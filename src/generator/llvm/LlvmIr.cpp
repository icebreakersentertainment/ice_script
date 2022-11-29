#include <memory>

#ifdef WIN32
#define NOMINMAX
#undef min
#undef max
#endif

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include "generator/llvm/LlvmIr.hpp"
#include "generator/llvm/LlvmIrVisitor.hpp"
#include "generator/llvm/Llvm.hpp"
#include "generator/llvm/Context.hpp"

#include "generator/llvm/detail/GenerateTypes.hpp"
#include "generator/llvm/detail/GenerateSymbols.hpp"
#include "generator/llvm/detail/GenerateDefaultDefinitions.hpp"

#include "asg/AsgPrinter.hpp"

namespace ice_script { namespace generator { namespace llvm {

using namespace ::llvm;
using namespace ice_script::generator::llvm::detail;

LlvmIr::LlvmIr(logger::ILogger& logger) : logger_(&logger)
{

}

std::string LlvmIr::generate(const TypeTable& typeTable, const SymbolTable& symbolTable, const asg::Asg& asg)
{
    std::shared_ptr<Context> context = std::make_shared<Context>(*logger_);
    context->setTypeTable(typeTable);
    context->setSymbolTable(symbolTable);

    std::shared_ptr<Llvm> llvm = std::make_shared<Llvm>();

    asg::AsgPrinter{std::cout}(asg);

    generateTypes(*context, *llvm);
    generateSymbols(*context, *llvm);
    generateDefaultDefinitions(*context, *llvm);

    LlvmIrVisitor visitor{*logger_, context, llvm};

    visitor(asg);

    std::string output;
    raw_string_ostream outputStream{output};
    outputStream << llvm->module();
    outputStream.flush();

    return output;
}

}}}