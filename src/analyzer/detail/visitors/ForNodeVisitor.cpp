#include "analyzer/detail/visitors/ForNodeVisitor.hpp"

#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ForNodeVisitorResultType ForNodeVisitor::operator()(const ast::VarNode& node)
{
    return process(*logger_, *context_, node);
}

ForNodeVisitorResultType ForNodeVisitor::operator()(const ast::ExprstatNode& node)
{
    return process(*logger_, *context_, node);
}

ForNodeVisitorResultType ForNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}

ForNodeVisitorResultType ForNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}


}}}