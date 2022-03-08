#include "generator/llvm/detail/generators/ConditionGenerator.hpp"

#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Condition& condition)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(condition).name())

    Scope& scope = context.scope();

    return process(logger, context, llvm, condition.expression.get());
}

}}}}