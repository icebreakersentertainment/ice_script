#ifndef ICE_SCRIPT_ANALYZER_VARACCESSNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_VARACCESSNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using VaraccessNodeVisitorResultType = boost::variant<
        asg::Scoperatore,
        asg::Identifier
>;

class VaraccessNodeVisitor : public AbstractVisitor<VaraccessNodeVisitor, VaraccessNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VaraccessNodeVisitorResultType operator()(const ast::ScopeNode& node)
    {
        return process(*context_, node);
    }

    VaraccessNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_VARACCESSNODEVISITOR_HPP
