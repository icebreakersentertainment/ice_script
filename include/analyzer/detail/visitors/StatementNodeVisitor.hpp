#ifndef ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

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

        StatementNodeVisitorResultType operator()(const ast::IfNode& node);
    StatementNodeVisitorResultType operator()(const ast::ForNode& node);
    StatementNodeVisitorResultType operator()(const ast::WhileNode& node);
    StatementNodeVisitorResultType operator()(const ast::ReturnNode& node);
    StatementNodeVisitorResultType operator()(const ast::StatblockNode& node);
    StatementNodeVisitorResultType operator()(const ast::BreakNode& node);
    StatementNodeVisitorResultType operator()(const ast::ContinueNode& node);
    StatementNodeVisitorResultType operator()(const ast::DowhileNode& node);
    StatementNodeVisitorResultType operator()(const ast::SwitchNode& node);
    StatementNodeVisitorResultType operator()(const ast::ExprstatNode& node);
    StatementNodeVisitorResultType operator()(const ast::TryNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_STATEMENTNODEVISITOR_HPP
