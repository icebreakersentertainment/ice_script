#ifndef ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using CaseNodeVisitorResultType = boost::variant<
        asg::Expression,
        asg::Statement
>;

class CaseNodeVisitor : public AbstractVisitor<CaseNodeVisitor, CaseNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    CaseNodeVisitorResultType operator()(const ast::ExprNode& node)
    {
        return process(*context_, node);
    }

    CaseNodeVisitorResultType operator()(const ast::StatementNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CASENODEVISITOR_HPP
