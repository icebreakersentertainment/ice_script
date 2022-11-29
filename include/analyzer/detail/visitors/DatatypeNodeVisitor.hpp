#ifndef ICE_SCRIPT_ANALYZER_DATATYPENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_DATATYPENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using DatatypeNodeVisitorResultType = boost::variant<
        asg::Identifier,
        asg::Primativetype
>;

class DatatypeNodeVisitor : public AbstractVisitor<DatatypeNodeVisitor, DatatypeNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    DatatypeNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    DatatypeNodeVisitorResultType operator()(const ast::PrimtypeNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_DATATYPENODEVISITOR_HPP
