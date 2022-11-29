#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"

#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Expressionstat& expressionstat)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expressionstat).name())

    Scope& scope = context.scope();

    if (expressionstat.assign)
    {
        return process(context, llvm, expressionstat.assign.get());
    }

    return nullptr;
}

}}}}