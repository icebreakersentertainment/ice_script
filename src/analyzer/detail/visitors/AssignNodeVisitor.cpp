#include "analyzer/detail/visitors/AssignNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ConditionNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

AssignNodeVisitorResultType AssignNodeVisitor::operator()(const ast::ConditionNode& node)
{
    return process(*logger_, *context_, node);
}

AssignNodeVisitorResultType AssignNodeVisitor::operator()(const ast::AssignopNode& node)
{
    return process(*logger_, *context_, node);
}


}}}