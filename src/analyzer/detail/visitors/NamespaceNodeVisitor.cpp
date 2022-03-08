#include "analyzer/detail/visitors/NamespaceNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ScriptNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

NamespaceNodeVisitorResultType NamespaceNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

NamespaceNodeVisitorResultType NamespaceNodeVisitor::operator()(const ast::ScriptNode& node)
{
    return process(*logger_, *context_, node);
}


}}}