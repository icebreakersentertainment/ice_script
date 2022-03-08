#include "analyzer/detail/visitors/VaraccessNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

VaraccessNodeVisitorResultType VaraccessNodeVisitor::operator()(const ast::ScopeNode& node)
{
    return process(*logger_, *context_, node);
}

VaraccessNodeVisitorResultType VaraccessNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}


}}}