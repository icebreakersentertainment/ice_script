#include "analyzer/detail/visitors/ExprvalueNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ConstructcallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VaraccessNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/CastNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LiteralNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/LambdaNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::VoidNode& node)
{
    return node.value;
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::ConstructcallNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::FunccallNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::VaraccessNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::CastNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::LiteralNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

ExprvalueNodeVisitorResultType ExprvalueNodeVisitor::operator()(const ast::LambdaNode& node)
{
    return process(*logger_, *context_, node);
}


}}}