#ifndef ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprtermNodeVisitorResultType = boost::variant<
        Type,
        asg::Initlist,
        asg::Expressionpreoperator,
        asg::Expressionvalue,
        asg::Expressionpostoperator
>;

class ExprtermNodeVisitor : public AbstractVisitor<ExprtermNodeVisitor, ExprtermNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExprtermNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    ExprtermNodeVisitorResultType operator()(const ast::InitlistNode& node)
    {
        return process(*context_, node);
    }

    ExprtermNodeVisitorResultType operator()(const ast::ExprpreopNode& node)
    {
        return process(*context_, node);
    }

    ExprtermNodeVisitorResultType operator()(const ast::ExprvalueNode& node)
    {
        return process(*context_, node);
    }

    ExprtermNodeVisitorResultType operator()(const ast::ExprpostopNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRTERMNODEVISITOR_HPP
