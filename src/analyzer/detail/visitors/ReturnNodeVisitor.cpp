#include "analyzer/detail/visitors/ReturnNodeVisitor.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ReturnNodeVisitorResultType ReturnNodeVisitor::operator()(const ast::AssignNode& node)
{
    return process(*logger_, *context_, node);
}


}}}