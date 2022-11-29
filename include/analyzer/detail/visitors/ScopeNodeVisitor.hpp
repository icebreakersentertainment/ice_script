#ifndef ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ScopeNodeVisitorResultType = boost::variant<
        asg::Identifier,
        Type
>;

class ScopeNodeVisitor : public AbstractVisitor<ScopeNodeVisitor, ScopeNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ScopeNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    ScopeNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP
