#include "analyzer/detail/visitors/ClassNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/VarNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncdefNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ClassNodeVisitorResultType ClassNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ClassNodeVisitorResultType ClassNodeVisitor::operator()(const ast::VirtpropNode& node)
{
    return process(*logger_, *context_, node);
}

ClassNodeVisitorResultType ClassNodeVisitor::operator()(const ast::FuncNode& node)
{
    return process(*logger_, *context_, node);
}

ClassNodeVisitorResultType ClassNodeVisitor::operator()(const ast::VarNode& node)
{
    return process(*logger_, *context_, node);
}

ClassNodeVisitorResultType ClassNodeVisitor::operator()(const ast::FuncdefNode& node)
{
    return process(*logger_, *context_, node);
}


}}}