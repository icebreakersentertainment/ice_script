#include "analyzer/detail/visitors/ScopeNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ScopeNodeVisitorResultType ScopeNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ScopeNodeVisitorResultType ScopeNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}


}}}