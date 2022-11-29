#ifndef ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using VarNodeVisitorResultType = boost::variant<
        asg::Initlist,
        asg::Expression,
        asg::Arglist
>;

class VarNodeVisitor : public AbstractVisitor<VarNodeVisitor, VarNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VarNodeVisitorResultType operator()(const ast::InitlistNode& node)
    {
        return process(*context_, node);
    }

    VarNodeVisitorResultType operator()(const ast::ExprNode& node)
    {
        return process(*context_, node);
    }

    VarNodeVisitorResultType operator()(const ast::ArglistNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_VARNODEVISITOR_HPP
