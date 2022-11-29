#ifndef ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ConstructcallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VaraccessNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CastNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LiteralNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LambdaNodeAnalyzer.hpp"

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

    ExprvalueNodeVisitorResultType operator()(const ast::VoidNode& node)
    {
        return node.value;
    }

    ExprvalueNodeVisitorResultType operator()(const ast::ConstructcallNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::FunccallNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::VaraccessNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::CastNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::LiteralNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }

    ExprvalueNodeVisitorResultType operator()(const ast::LambdaNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRVALUENODEVISITOR_HPP
