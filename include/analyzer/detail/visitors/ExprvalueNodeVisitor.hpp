#ifndef ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprvalueNodeVisitorResultType = boost::variant<
        ast::Void,
        asg::Constructcall,
        asg::Functioncall,
        asg::Variableaccess,
        asg::Cast,
        asg::Literal,
        asg::Assign,
        asg::Lambda
>;

class ExprvalueNodeVisitor : public AbstractVisitor<ExprvalueNodeVisitor, ExprvalueNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExprvalueNodeVisitorResultType operator()(const ast::VoidNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::ConstructcallNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::FunccallNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::VaraccessNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::CastNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::LiteralNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::AssignNode& node);
    ExprvalueNodeVisitorResultType operator()(const ast::LambdaNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP
