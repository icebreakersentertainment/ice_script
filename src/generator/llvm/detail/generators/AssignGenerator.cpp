#include "generator/llvm/detail/generators/AssignGenerator.hpp"

#include "generator/llvm/detail/generators/ConditionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Assign& assign)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(assign).name())

    Scope& scope = context.scope();

    return process(logger, context, llvm, assign.condition.get());
}

}}}}