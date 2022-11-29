#ifndef ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IfNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ForNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/WhileNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ReturnNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BreakNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ContinueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DowhileNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/SwitchNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TryNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using StatementNodeVisitorResultType = boost::variant<
        asg::If,
        asg::For,
        asg::While,
        asg::Return,
        asg::Statblock,
        asg::Break,
        asg::Continue,
        asg::Dowhile,
        asg::Switch,
        asg::Expressionstat,
        asg::Try
>;

class StatementNodeVisitor : public AbstractVisitor<StatementNodeVisitor, StatementNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    StatementNodeVisitorResultType operator()(const ast::IfNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::ForNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::WhileNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::ReturnNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::StatblockNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::BreakNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::ContinueNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::DowhileNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::SwitchNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::ExprstatNode& node)
    {
        return process(*context_, node);
    }

    StatementNodeVisitorResultType operator()(const ast::TryNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP
