#ifndef ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using IfNodeVisitorResultType = boost::variant<
        asg::Assign,
        asg::Statement
>;

class IfNodeVisitor : public AbstractVisitor<IfNodeVisitor, IfNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    IfNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }

    IfNodeVisitorResultType operator()(const ast::StatementNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_IFNODEVISITOR_HPP
