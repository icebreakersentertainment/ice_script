#include "analyzer/detail/visitors/DatatypeNodeVisitor.hpp"

#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

DatatypeNodeVisitorResultType DatatypeNodeVisitor::operator()(const ast::IdentifierNode& node)
{
    return process(*logger_, *context_, node);
}

DatatypeNodeVisitorResultType DatatypeNodeVisitor::operator()(const ast::PrimtypeNode& node)
{
    return process(*logger_, *context_, node);
}


}}}