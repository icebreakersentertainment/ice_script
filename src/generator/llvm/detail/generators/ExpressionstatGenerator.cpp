#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionstat& expressionstat)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expressionstat).name())

    Scope& scope = context.scope();

    return nullptr;
}

}}}}