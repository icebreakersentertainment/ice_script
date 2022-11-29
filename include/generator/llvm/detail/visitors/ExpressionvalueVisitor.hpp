#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ConstructcallGenerator.hpp"
#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"
#include "generator/llvm/detail/generators/VariableaccessGenerator.hpp"
#include "generator/llvm/detail/generators/CastGenerator.hpp"
#include "generator/llvm/detail/generators/LiteralGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/LambdaGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionvalueVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ExpressionvalueVisitor : public AbstractVisitor<ExpressionvalueVisitor, ExpressionvalueVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExpressionvalueVisitorResultType operator()(const ast::Void& voidType)
    {
    //    return process(*context_, *llvm_, voidType);
        return nullptr;
    }

    ExpressionvalueVisitorResultType operator()(const asg::Constructcall& constructcall)
    {
        return process(*context_, *llvm_, constructcall);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Functioncall& functioncall)
    {
        return process(*context_, *llvm_, functioncall);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Variableaccess& variableaccess)
    {
        return process(*context_, *llvm_, variableaccess);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Cast& cast)
    {
        return process(*context_, *llvm_, cast);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Literal& literal)
    {
        return process(*context_, *llvm_, literal);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

    ExpressionvalueVisitorResultType operator()(const asg::Lambda& lambda)
    {
        return process(*context_, *llvm_, lambda);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP
