#include "analyzer/detail/visitors/IntfmthdNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

IntfmthdNodeVisitorResultType IntfmthdNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

IntfmthdNodeVisitorResultType IntfmthdNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

IntfmthdNodeVisitorResultType IntfmthdNodeVisitor::operator()(const ast::ParamlistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}