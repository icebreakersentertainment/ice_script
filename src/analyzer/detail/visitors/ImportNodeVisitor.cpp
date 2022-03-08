#include "analyzer/detail/visitors/ImportNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/FuncattrNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ImportNodeVisitorResultType ImportNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

ImportNodeVisitorResultType ImportNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

ImportNodeVisitorResultType ImportNodeVisitor::operator()(const ast::ParamlistNode& node)
{
    return process(*logger_, *context_, node);
}

ImportNodeVisitorResultType ImportNodeVisitor::operator()(const ast::FuncattrNode& node)
{
    return process(*logger_, *context_, node);
}

ImportNodeVisitorResultType ImportNodeVisitor::operator()(const ast::StringNode& node)
{
    return process(*logger_, *context_, node);
}


}}}