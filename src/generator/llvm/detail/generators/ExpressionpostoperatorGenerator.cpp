#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionpostoperatorVisitor.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Expressionpostoperator& expressionpostoperator)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expressionpostoperator).name())

    Scope& scope = context.scope();

    ExpressionpostoperatorVisitor visitor{context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expressionpostoperator.value));
}

}}}}