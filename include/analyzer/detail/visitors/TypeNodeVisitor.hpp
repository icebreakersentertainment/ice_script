#ifndef ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DatatypeNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using TypeNodeVisitorResultType = boost::variant<
        asg::Scoperatore,
        asg::Datatype
>;

class TypeNodeVisitor : public AbstractVisitor<TypeNodeVisitor, TypeNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    TypeNodeVisitorResultType operator()(const ast::ScopeNode& node)
    {
        return process(*context_, node);
    }

    TypeNodeVisitorResultType operator()(const ast::DatatypeNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP
