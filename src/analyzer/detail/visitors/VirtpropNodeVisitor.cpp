#include "analyzer/detail/visitors/VirtpropNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

VirtpropNodeVisitorResultType VirtpropNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

VirtpropNodeVisitorResultType VirtpropNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

VirtpropNodeVisitorResultType VirtpropNodeVisitor::operator()(const ast::FuncattrNode& node)
{
    return process(*logger_, *context_, node);
}

VirtpropNodeVisitorResultType VirtpropNodeVisitor::operator()(const ast::StatblockNode& node)
{
    return process(*logger_, *context_, node);
}


}}}