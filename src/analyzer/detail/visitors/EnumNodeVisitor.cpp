#include "analyzer/detail/visitors/EnumNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

EnumNodeVisitorResultType EnumNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

EnumNodeVisitorResultType EnumNodeVisitor::operator()(const ast::ExprNode& node)
{
    return process(*logger_, *context_, node);
}


}}}