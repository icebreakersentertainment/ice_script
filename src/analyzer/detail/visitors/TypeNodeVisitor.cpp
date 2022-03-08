#include "analyzer/detail/visitors/TypeNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DatatypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

TypeNodeVisitorResultType TypeNodeVisitor::operator()(const ast::ScopeNode& node)
{
    return process(*logger_, *context_, node);
}

TypeNodeVisitorResultType TypeNodeVisitor::operator()(const ast::DatatypeNode& node)
{
    return process(*logger_, *context_, node);
}


}}}