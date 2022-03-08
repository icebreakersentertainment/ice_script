#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

    ExpressionvalueVisitorResultType operator()(const ast::Void& voidType);
    ExpressionvalueVisitorResultType operator()(const asg::Constructcall& constructcall);
    ExpressionvalueVisitorResultType operator()(const asg::Functioncall& functioncall);
    ExpressionvalueVisitorResultType operator()(const asg::Variableaccess& variableaccess);
    ExpressionvalueVisitorResultType operator()(const asg::Cast& cast);
    ExpressionvalueVisitorResultType operator()(const asg::Literal& literal);
    ExpressionvalueVisitorResultType operator()(const asg::Assign& assign);
    ExpressionvalueVisitorResultType operator()(const asg::Lambda& lambda);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONVALUEVISITOR_HPP
