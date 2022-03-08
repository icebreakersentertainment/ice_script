#ifndef ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using ScopeNodeVisitorResultType = boost::variant<
            asg::Identifier,
    asg::Type
>;

class ScopeNodeVisitor : public AbstractVisitor<ScopeNodeVisitor, ScopeNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        ScopeNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    ScopeNodeVisitorResultType operator()(const ast::TypeNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_SCOPENODEVISITOR_HPP
