#ifndef ICE_SCRIPT_ANALYZER_NAMESPACENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_NAMESPACENODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using NamespaceNodeVisitorResultType = boost::variant<
            asg::Identifier,
    asg::Script
>;

class NamespaceNodeVisitor : public AbstractVisitor<NamespaceNodeVisitor, NamespaceNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        NamespaceNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    NamespaceNodeVisitorResultType operator()(const ast::ScriptNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_NAMESPACENODEVISITOR_HPP
