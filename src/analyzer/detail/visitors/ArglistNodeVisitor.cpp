#include "analyzer/detail/visitors/ArglistNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ArglistNodeVisitorResultType ArglistNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ArglistNodeVisitorResultType ArglistNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}


}}}