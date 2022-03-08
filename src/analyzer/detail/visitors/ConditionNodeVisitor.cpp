#include "analyzer/detail/visitors/ConditionNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ConditionNodeVisitorResultType ConditionNodeVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}

ConditionNodeVisitorResultType ConditionNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}


}}}