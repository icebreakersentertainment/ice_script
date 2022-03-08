#include "analyzer/detail/visitors/CaseNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

CaseNodeVisitorResultType CaseNodeVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}

CaseNodeVisitorResultType CaseNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}


}}}