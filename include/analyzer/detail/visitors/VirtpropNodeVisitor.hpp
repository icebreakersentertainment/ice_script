#ifndef ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using VirtpropNodeVisitorResultType = boost::variant<
        Type,
        asg::Identifier,
        asg::Functionattribute,
        asg::Statblock
>;

class VirtpropNodeVisitor : public AbstractVisitor<VirtpropNodeVisitor, VirtpropNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VirtpropNodeVisitorResultType operator()(const ast::TypeNode& node)
    {
        return process(*context_, node);
    }

    VirtpropNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    VirtpropNodeVisitorResultType operator()(const ast::FuncattrNode& node)
    {
        return process(*context_, node);
    }

    VirtpropNodeVisitorResultType operator()(const ast::StatblockNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP
