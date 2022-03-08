#include "analyzer/detail/visitors/ExprtermNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ExprtermNodeVisitorResultType ExprtermNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

ExprtermNodeVisitorResultType ExprtermNodeVisitor::operator()(const ast::InitlistNode& node)
{
    return process(*logger_, *context_, node);
}

ExprtermNodeVisitorResultType ExprtermNodeVisitor::operator()(const ast::ExprpreopNode& node)
{
    return process(*logger_, *context_, node);
}

ExprtermNodeVisitorResultType ExprtermNodeVisitor::operator()(const ast::ExprvalueNode& node)
{
    return process(*logger_, *context_, node);
}

ExprtermNodeVisitorResultType ExprtermNodeVisitor::operator()(const ast::ExprpostopNode& node)
{
    return process(*logger_, *context_, node);
}


}}}