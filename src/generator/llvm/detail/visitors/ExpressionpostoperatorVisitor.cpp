#include "generator/llvm/detail/visitors/ExpressionpostoperatorVisitor.hpp"

#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionpostoperatorVisitorResultType ExpressionpostoperatorVisitor::operator()(const asg::Functioncall& functioncall)
{
    return process(*logger_, *context_, *llvm_, functioncall);
}

ExpressionpostoperatorVisitorResultType ExpressionpostoperatorVisitor::operator()(const asg::Variable& variable)
{
    return process(*logger_, *context_, *llvm_, variable);
}

ExpressionpostoperatorVisitorResultType ExpressionpostoperatorVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ExpressionpostoperatorVisitorResultType ExpressionpostoperatorVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}

ExpressionpostoperatorVisitorResultType ExpressionpostoperatorVisitor::operator()(const asg::Arglist& arglist)
{
    return process(*logger_, *context_, *llvm_, arglist);
}


}}}}