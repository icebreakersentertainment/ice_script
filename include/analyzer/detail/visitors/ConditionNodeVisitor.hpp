#ifndef ICE_SCRIPT_ANALYZER_CONDITIONNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CONDITIONNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ConditionNodeVisitorResultType = boost::variant<
        asg::Expression,
        asg::Assign
>;

class ConditionNodeVisitor : public AbstractVisitor<ConditionNodeVisitor, ConditionNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ConditionNodeVisitorResultType operator()(const ast::ExprNode& node)
    {
        return process(*context_, node);
    }

    ConditionNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CONDITIONNODEVISITOR_HPP
