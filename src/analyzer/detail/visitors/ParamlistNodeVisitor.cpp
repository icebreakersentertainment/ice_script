#include "analyzer/detail/visitors/ParamlistNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ParamlistNodeVisitorResultType ParamlistNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

ParamlistNodeVisitorResultType ParamlistNodeVisitor::operator()(const ast::TypemodNode& node)
{
    return process(*logger_, *context_, node);
}

ParamlistNodeVisitorResultType ParamlistNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ParamlistNodeVisitorResultType ParamlistNodeVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}


}}}