#include "analyzer/detail/visitors/FuncdefNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

FuncdefNodeVisitorResultType FuncdefNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

FuncdefNodeVisitorResultType FuncdefNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

FuncdefNodeVisitorResultType FuncdefNodeVisitor::operator()(const ast::ParamlistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}