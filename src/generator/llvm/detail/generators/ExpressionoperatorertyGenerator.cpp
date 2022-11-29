#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionoperatorertyVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionoperatorertyVisitorResultType process(Context& context, Llvm& llvm, const asg::Expressionoperatorerty& expressionoperatorerty)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expressionoperatorerty).name())

    Scope& scope = context.scope();

    ExpressionoperatorertyVisitor visitor{context, llvm};
    return boost::apply_visitor(visitor, expressionoperatorerty.value);
}

}}}}