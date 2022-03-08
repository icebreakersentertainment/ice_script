#include "analyzer/detail/visitors/FunccallNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

FunccallNodeVisitorResultType FunccallNodeVisitor::operator()(const ast::ScopeNode& node)
{
    return process(*logger_, *context_, node);
}

FunccallNodeVisitorResultType FunccallNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

FunccallNodeVisitorResultType FunccallNodeVisitor::operator()(const ast::ArglistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}