#ifndef ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/MathopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CompopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LogicopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitopNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ExpropNodeVisitorResultType = boost::variant<
        asg::Mathoperator,
        asg::Comparisonoperator,
        asg::Logicoperator,
        asg::Bitoperator
>;

class ExpropNodeVisitor : public AbstractVisitor<ExpropNodeVisitor, ExpropNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExpropNodeVisitorResultType operator()(const ast::MathopNode& node)
    {
        return process(*context_, node);
    }

    ExpropNodeVisitorResultType operator()(const ast::CompopNode& node)
    {
        return process(*context_, node);
    }

    ExpropNodeVisitorResultType operator()(const ast::LogicopNode& node)
    {
        return process(*context_, node);
    }

    ExpropNodeVisitorResultType operator()(const ast::BitopNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPROPNODEVISITOR_HPP
