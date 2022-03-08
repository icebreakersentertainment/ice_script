#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionoperatorertyVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionoperatorertyVisitorResultType process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionoperatorerty& expressionoperatorerty)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expressionoperatorerty).name())

    Scope& scope = context.scope();

    ExpressionoperatorertyVisitor visitor{logger, context, llvm};
    return boost::apply_visitor(visitor, expressionoperatorerty.value);
}

}}}}