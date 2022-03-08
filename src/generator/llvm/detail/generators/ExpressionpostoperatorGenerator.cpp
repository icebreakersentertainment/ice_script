#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionpostoperatorVisitor.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionpostoperator& expressionpostoperator)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expressionpostoperator).name())

    Scope& scope = context.scope();

    ExpressionpostoperatorVisitor visitor{logger, context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expressionpostoperator.value));
}

}}}}