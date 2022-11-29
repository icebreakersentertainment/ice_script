#ifndef ICE_SCRIPT_ANALYZER_FUNCDEFNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FUNCDEFNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using FuncdefNodeVisitorResultType = boost::variant<
        Type,
        asg::Identifier,
        asg::Parameterlist
>;

class FuncdefNodeVisitor : public AbstractVisitor<FuncdefNodeVisitor, FuncdefNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FuncdefNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    FuncdefNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    FuncdefNodeVisitorResultType operator()(const ast::ParamlistNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCDEFNODEVISITOR_HPP
