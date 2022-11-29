#ifndef ICE_SCRIPT_ANALYZER_TYPEDEFNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_TYPEDEFNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using TypedefNodeVisitorResultType = boost::variant<
        asg::Primativetype,
        asg::Identifier
>;

class TypedefNodeVisitor : public AbstractVisitor<TypedefNodeVisitor, TypedefNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    TypedefNodeVisitorResultType operator()(const ast::PrimtypeNode& node)
    {
        return process(*context_, node);
    }

    TypedefNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPEDEFNODEVISITOR_HPP
