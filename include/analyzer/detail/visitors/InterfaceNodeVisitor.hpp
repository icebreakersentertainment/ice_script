#ifndef ICE_SCRIPT_ANALYZER_INTERFACENODEVISITOR_HPP
#define ICE_SCRIPT_ANALYZER_INTERFACENODEVISITOR_HPP

#include "ast/Ast.hpp"
#include "asg/Asg.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IntfmthdNodeAnalyzer.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using InterfaceNodeVisitorResultType = boost::variant<
        asg::Identifier,
        asg::Virtualproperatorerty,
        asg::Interfacemethod
>;

class InterfaceNodeVisitor : public AbstractVisitor<InterfaceNodeVisitor, InterfaceNodeVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    InterfaceNodeVisitorResultType operator()(const ast::IdentifierNode& node)
    {
        return process(*context_, node);
    }

    InterfaceNodeVisitorResultType operator()(const ast::VirtpropNode& node)
    {
        return process(*context_, node);
    }

    InterfaceNodeVisitorResultType operator()(const ast::IntfmthdNode& node)
    {
        return process(*context_, node);
    }
};

}}}

#endif //ICE_SCRIPT_ANALYZER_INTERFACENODEVISITOR_HPP
