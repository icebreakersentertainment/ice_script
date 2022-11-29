#ifndef ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExprNodeVisitorResultType = boost::variant<
        asg::Expressionterm,
        asg::Expressionoperatorerty
>;

class ExprNodeVisitor : public AbstractVisitor<ExprNodeVisitor, ExprNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExprNodeVisitorResultType operator()(const ast::ExprtermNode& node)
    {
        return process(*context_, node);
    }

    ExprNodeVisitorResultType operator()(const ast::ExpropNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRNODEVISITOR_HPP
