#include "analyzer/detail/visitors/ConstructcallNodeVisitor.hpp"

#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

ConstructcallNodeVisitorResultType ConstructcallNodeVisitor::operator()(const ast::TypeNode& node)
{
    return process(*logger_, *context_, node);
}

ConstructcallNodeVisitorResultType ConstructcallNodeVisitor::operator()(const ast::ArglistNode& node)
{
    return process(*logger_, *context_, node);
}


}}}