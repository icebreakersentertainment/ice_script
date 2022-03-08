#include "generator/llvm/detail/generators/ReturnGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ::llvm;
using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Return& returnStatement)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(returnStatement).name())

    Scope& scope = context.scope();

    if (returnStatement.assignment)
    {
        auto result = process(logger, context, llvm, returnStatement.assignment.get());
        return llvm.builder().CreateRet(result);
    }

    return llvm.builder().CreateRetVoid();
//    return nullptr;
}

}}}}