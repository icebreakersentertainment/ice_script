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

namespace ice_script { namespace generator { namespace llvm {

using namespace ::llvm;

LlvmIr::LlvmIr(logger::ILogger& logger) : logger_(&logger)
{

}

std::string LlvmIr::generate(const asg::Asg& asg)
{
    std::shared_ptr<Context> context = std::make_shared<Context>();
    std::shared_ptr<Llvm> llvm = std::make_shared<Llvm>();

    LlvmIrVisitor visitor{*logger_, context, llvm};

    visitor(asg);

    std::string output;
    raw_string_ostream outputStream{output};
    outputStream << llvm->module();
    outputStream.flush();

    return output;
}

}}}