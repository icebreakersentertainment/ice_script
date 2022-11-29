#include "generator/llvm/detail/generators/ExpressionpreoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Expressionpreoperator& expressionpreoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expressionpreoperator).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}