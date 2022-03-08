#include "analyzer/detail/visitors/CastNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

CastNodeVisitorResultType CastNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

CastNodeVisitorResultType CastNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}


}}}