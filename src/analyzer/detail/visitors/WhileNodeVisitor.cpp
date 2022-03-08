#include "analyzer/detail/visitors/WhileNodeVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

WhileNodeVisitorResultType WhileNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

WhileNodeVisitorResultType WhileNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}


}}}