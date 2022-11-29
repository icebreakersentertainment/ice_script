#ifndef ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ArglistNodeVisitorResultType = boost::variant<
        asg::Identifier,
        asg::Assign
>;

class ArglistNodeVisitor : public AbstractVisitor<ArglistNodeVisitor, ArglistNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ArglistNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    ArglistNodeVisitorResultType operator()(const ast::AssignNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_ARGLISTNODEVISITOR_HPP
