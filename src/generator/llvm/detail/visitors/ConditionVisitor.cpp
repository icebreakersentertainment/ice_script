#include "generator/llvm/detail/visitors/ConditionVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ConditionVisitorResultType ConditionVisitor::operator()(const asg::Expression& expression)
{
    return process(*logger_, *context_, *llvm_, expression);
}

ConditionVisitorResultType ConditionVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}


}}}}