#include "analyzer/detail/visitors/SwitchNodeVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CaseNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

SwitchNodeVisitorResultType SwitchNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

SwitchNodeVisitorResultType SwitchNodeVisitor::operator()(const ast::CaseNode& node)
{
    return process(*logger_, *context_, node);
}


}}}