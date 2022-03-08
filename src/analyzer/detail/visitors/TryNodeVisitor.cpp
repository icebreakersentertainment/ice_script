#include "analyzer/detail/visitors/TryNodeVisitor.hpp"

#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

TryNodeVisitorResultType TryNodeVisitor::operator()(const ast::StatblockNode& node)
{
    return process(*logger_, *context_, node);
}


}}}