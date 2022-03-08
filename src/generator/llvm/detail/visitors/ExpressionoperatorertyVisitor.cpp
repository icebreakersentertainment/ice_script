#include "generator/llvm/detail/visitors/ExpressionoperatorertyVisitor.hpp"

#include "generator/llvm/detail/generators/MathoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ComparisonoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/LogicoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/BitoperatorGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionoperatorertyVisitorResultType ExpressionoperatorertyVisitor::operator()(const asg::Mathoperator& mathoperator)
{
    return process(*logger_, *context_, *llvm_, mathoperator);
}

ExpressionoperatorertyVisitorResultType ExpressionoperatorertyVisitor::operator()(const asg::Comparisonoperator& comparisonoperator)
{
    return process(*logger_, *context_, *llvm_, comparisonoperator);
}

ExpressionoperatorertyVisitorResultType ExpressionoperatorertyVisitor::operator()(const asg::Logicoperator& logicoperator)
{
    return process(*logger_, *context_, *llvm_, logicoperator);
}

ExpressionoperatorertyVisitorResultType ExpressionoperatorertyVisitor::operator()(const asg::Bitoperator& bitoperator)
{
    return process(*logger_, *context_, *llvm_, bitoperator);
}


}}}}