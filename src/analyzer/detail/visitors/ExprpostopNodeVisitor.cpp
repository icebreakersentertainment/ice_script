#include "analyzer/detail/visitors/ExprpostopNodeVisitor.hpp"

#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ExprpostopNodeVisitorResultType ExprpostopNodeVisitor::operator()(const ast::FunccallNode& node)
{
    return process(*logger_, *context_, node);
}

ExprpostopNodeVisitorResultType ExprpostopNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ExprpostopNodeVisitorResultType ExprpostopNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

ExprpostopNodeVisitorResultType ExprpostopNodeVisitor::operator()(const ast::ArglistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}