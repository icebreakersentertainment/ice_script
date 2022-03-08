#include "generator/llvm/detail/visitors/ExpressionVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionVisitorResultType ExpressionVisitor::operator()(const asg::Expressionterm& expressionterm)
{
    return process(*logger_, *context_, *llvm_, expressionterm);
}

ExpressionVisitorResultType ExpressionVisitor::operator()(const asg::Expressionoperatorerty& expressionoperatorerty)
{
    return process(*logger_, *context_, *llvm_, expressionoperatorerty);
}


}}}}