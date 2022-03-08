#include "analyzer/detail/visitors/LiteralNodeVisitor.hpp"

#include "analyzer/detail/analyzers/NumberNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BitsNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

LiteralNodeVisitorResultType LiteralNodeVisitor::operator()(const ast::NumberNode& node)
{
    return process(*logger_, *context_, node);
}

LiteralNodeVisitorResultType LiteralNodeVisitor::operator()(const ast::StringNode& node)
{
    return process(*logger_, *context_, node);
}

LiteralNodeVisitorResultType LiteralNodeVisitor::operator()(const ast::BitsNode& node)
{
    return process(*logger_, *context_, node);
}

LiteralNodeVisitorResultType LiteralNodeVisitor::operator()(const ast::BoolNode& node)
{
    return node.value;
}

LiteralNodeVisitorResultType LiteralNodeVisitor::operator()(const ast::NullNode& node)
{
    return node.value;
}


}}}