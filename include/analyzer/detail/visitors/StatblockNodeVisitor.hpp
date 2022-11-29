#ifndef ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using StatblockNodeVisitorResultType = boost::variant<
        asg::Variable,
        asg::Statement
>;

class StatblockNodeVisitor : public AbstractVisitor<StatblockNodeVisitor, StatblockNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    StatblockNodeVisitorResultType operator()(const ast::VarNode& node)
    {
        return process(*context_, node);
    }

    StatblockNodeVisitorResultType operator()(const ast::StatementNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_STATBLOCKNODEVISITOR_HPP
