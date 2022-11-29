#ifndef ICE_SCRIPT_ANALYZER_WHILENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_WHILENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using WhileNodeVisitorResultType = boost::variant<
        asg::Assign,
        asg::Statement
>;

class WhileNodeVisitor : public AbstractVisitor<WhileNodeVisitor, WhileNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    WhileNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }

    WhileNodeVisitorResultType operator()(const ast::StatementNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_WHILENODEVISITOR_HPP
