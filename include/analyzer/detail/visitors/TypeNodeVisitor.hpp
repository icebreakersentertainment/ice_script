#ifndef ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

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

        TypeNodeVisitorResultType operator()(const ast::ScopeNode& node);
    TypeNodeVisitorResultType operator()(const ast::DatatypeNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPENODEVISITOR_HPP
