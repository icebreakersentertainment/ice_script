#include "analyzer/detail/visitors/StatblockNodeVisitor.hpp"

#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

StatblockNodeVisitorResultType StatblockNodeVisitor::operator()(const ast::VarNode& node)
{
    return process(*logger_, *context_, node);
}

StatblockNodeVisitorResultType StatblockNodeVisitor::operator()(const ast::StatementNode& node)
{
    return process(*logger_, *context_, node);
}


}}}