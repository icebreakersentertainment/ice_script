#include "analyzer/detail/visitors/LambdaNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

LambdaNodeVisitorResultType LambdaNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

LambdaNodeVisitorResultType LambdaNodeVisitor::operator()(const ast::TypemodNode& node)
{
    return process(*logger_, *context_, node);
}

LambdaNodeVisitorResultType LambdaNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

LambdaNodeVisitorResultType LambdaNodeVisitor::operator()(const ast::StatblockNode& node)
{
    return process(*logger_, *context_, node);
}


}}}