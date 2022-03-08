#ifndef ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP

#include <string>

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using VirtpropNodeVisitorResultType = boost::variant<
            asg::Type,
    asg::Identifier,
    asg::Functionattribute,
    asg::Statblock
>;

class VirtpropNodeVisitor : public AbstractVisitor<VirtpropNodeVisitor, VirtpropNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        VirtpropNodeVisitorResultType operator()(const ast::TypeNode& node);
    VirtpropNodeVisitorResultType operator()(const ast::IdentifierNode& node);
    VirtpropNodeVisitorResultType operator()(const ast::FuncattrNode& node);
    VirtpropNodeVisitorResultType operator()(const ast::StatblockNode& node);
};

}}}

#endif //ICE_SCRIPT_ANALYZER_VIRTPROPNODEVISITOR_HPP
