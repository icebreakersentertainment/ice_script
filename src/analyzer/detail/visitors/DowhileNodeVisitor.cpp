#include "analyzer/detail/visitors/DowhileNodeVisitor.hpp"

#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

DowhileNodeVisitorResultType DowhileNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}

DowhileNodeVisitorResultType DowhileNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}


}}}