#ifndef ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using FuncNodeVisitorResultType = boost::variant<
        Type,
        asg::Identifier,
        asg::Parameterlist,
        asg::Functionattribute,
        asg::Statblock
>;

class FuncNodeVisitor : public AbstractVisitor<FuncNodeVisitor, FuncNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FuncNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    FuncNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    FuncNodeVisitorResultType operator()(const ast::ParamlistNode& node)
    {
        return process(*context_, node);
    }

    FuncNodeVisitorResultType operator()(const ast::FuncattrNode& node)
    {
        return process(*context_, node);
    }

    FuncNodeVisitorResultType operator()(const ast::StatblockNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCNODEVISITOR_HPP
