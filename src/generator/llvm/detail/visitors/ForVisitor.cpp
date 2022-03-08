#include "generator/llvm/detail/visitors/ForVisitor.hpp"

#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ForVisitorResultType ForVisitor::operator()(const asg::Variable& variable)
{
    return process(*logger_, *context_, *llvm_, variable);
}

ForVisitorResultType ForVisitor::operator()(const asg::Expressionstat& expressionstat)
{
    return process(*logger_, *context_, *llvm_, expressionstat);
}

ForVisitorResultType ForVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}

ForVisitorResultType ForVisitor::operator()(const asg::Statement& statement)
{
    return process(*logger_, *context_, *llvm_, statement);
}


}}}}