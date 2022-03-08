#include "generator/llvm/detail/visitors/ExpressionvalueVisitor.hpp"

#include "generator/llvm/detail/generators/ConstructcallGenerator.hpp"
#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"
#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"
#include "generator/llvm/detail/generators/CastGenerator.hpp"
#include "generator/llvm/detail/generators/LiteralGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/LambdaGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const ast::Void& voidType)
{
//    return process(*logger_, *context_, *llvm_, voidType);
    std::cout << "ASDF ASDF ASD F" << std::endl;
    return nullptr;
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Constructcall& constructcall)
{
    return process(*logger_, *context_, *llvm_, constructcall);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Functioncall& functioncall)
{
    return process(*logger_, *context_, *llvm_, functioncall);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Variableaccess& variableaccess)
{
    return process(*logger_, *context_, *llvm_, variableaccess);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Cast& cast)
{
    return process(*logger_, *context_, *llvm_, cast);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Literal& literal)
{
    return process(*logger_, *context_, *llvm_, literal);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Assign& assign)
{
    return process(*logger_, *context_, *llvm_, assign);
}

ExpressionvalueVisitorResultType ExpressionvalueVisitor::operator()(const asg::Lambda& lambda)
{
    return process(*logger_, *context_, *llvm_, lambda);
}


}}}}