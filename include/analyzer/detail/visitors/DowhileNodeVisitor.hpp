#ifndef ICE_SCRIPT_ANALYZER_DOWHILENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_DOWHILENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using DowhileNodeVisitorResultType = boost::variant<
        asg::Statement,
        asg::Assign
>;

class DowhileNodeVisitor : public AbstractVisitor<DowhileNodeVisitor, DowhileNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    DowhileNodeVisitorResultType operator()(const ast::StatementNode& node)
    {
        return process(*context_, node);
    }

    DowhileNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_DOWHILENODEVISITOR_HPP
