#include "generator/llvm/detail/generators/ReturnGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Return& returnStatement)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(returnStatement).name())

    Scope& scope = context.scope();

    if (returnStatement.assignment)
    {
        auto result = process(context, llvm, returnStatement.assignment.get());

        if (::llvm::isa<::llvm::AllocaInst>(result))
        {
            ::llvm::AllocaInst* allocaInst = ::llvm::dyn_cast<::llvm::AllocaInst>(result);
            result = llvm.builder().CreateLoad(allocaInst);
        }
        else if (::llvm::isa<::llvm::GetElementPtrInst>(result))
        {
            ::llvm::GetElementPtrInst* getElementPtrInst = ::llvm::dyn_cast<::llvm::GetElementPtrInst>(result);
            result = llvm.builder().CreateLoad(getElementPtrInst);
        }

        return llvm.builder().CreateRet(result);
    }

    return llvm.builder().CreateRetVoid();
}

}}}}