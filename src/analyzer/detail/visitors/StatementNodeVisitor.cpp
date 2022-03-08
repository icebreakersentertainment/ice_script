#include "analyzer/detail/visitors/StatementNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IfNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ForNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/WhileNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ReturnNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/BreakNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ContinueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/DowhileNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/SwitchNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/TryNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::IfNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::ForNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::WhileNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::ReturnNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::StatblockNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::BreakNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::ContinueNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::DowhileNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::SwitchNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::ExprstatNode& node)
{
    return process(*logger_, *context_, node);
}

StatementNodeVisitorResultType StatementNodeVisitor::operator()(const ast::TryNode& node)
{
    return process(*logger_, *context_, node);
}


}}}