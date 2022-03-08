#include "analyzer/detail/visitors/IfNodeVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

IfNodeVisitorResultType IfNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

IfNodeVisitorResultType IfNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}


}}}