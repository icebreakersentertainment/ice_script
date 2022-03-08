#include "analyzer/detail/visitors/VarNodeVisitor.hpp"

#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

VarNodeVisitorResultType VarNodeVisitor::operator()(const ast::InitlistNode& node)
{
    return process(*logger_, *context_, node);
}

VarNodeVisitorResultType VarNodeVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}

VarNodeVisitorResultType VarNodeVisitor::operator()(const ast::ArglistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}