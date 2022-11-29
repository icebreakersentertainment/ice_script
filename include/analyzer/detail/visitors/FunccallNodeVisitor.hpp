#ifndef ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using FunccallNodeVisitorResultType = boost::variant<
        asg::Scoperatore,
        asg::Identifier,
        asg::Arglist
>;

class FunccallNodeVisitor : public AbstractVisitor<FunccallNodeVisitor, FunccallNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FunccallNodeVisitorResultType operator()(const ast::ScopeNode& node)
    {
        return process(*context_, node);
    }

    FunccallNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    FunccallNodeVisitorResultType operator()(const ast::ArglistNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCCALLNODEVISITOR_HPP
