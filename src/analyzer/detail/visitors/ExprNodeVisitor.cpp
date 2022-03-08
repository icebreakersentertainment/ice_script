#include "analyzer/detail/visitors/ExprNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ExprNodeVisitorResultType ExprNodeVisitor::operator()(const ast::ExprtermNode& node)
{
    return process(*logger_, *context_, node);
}

ExprNodeVisitorResultType ExprNodeVisitor::operator()(const ast::ExpropNode& node)
{
    return process(*logger_, *context_, node);
}


}}}