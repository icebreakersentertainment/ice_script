#include "analyzer/detail/visitors/TypedefNodeVisitor.hpp"

#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

TypedefNodeVisitorResultType TypedefNodeVisitor::operator()(const ast::PrimtypeNode& node)
{
    return process(*logger_, *context_, node);
}

TypedefNodeVisitorResultType TypedefNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}


}}}