#include "analyzer/detail/visitors/InterfaceNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IntfmthdNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

InterfaceNodeVisitorResultType InterfaceNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

InterfaceNodeVisitorResultType InterfaceNodeVisitor::operator()(const ast::VirtpropNode& node)
{
    return process(*logger_, *context_, node);
}

InterfaceNodeVisitorResultType InterfaceNodeVisitor::operator()(const ast::IntfmthdNode& node)
{
    return process(*logger_, *context_, node);
}


}}}