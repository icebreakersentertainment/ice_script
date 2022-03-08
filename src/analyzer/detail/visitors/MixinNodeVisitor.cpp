#include "analyzer/detail/visitors/MixinNodeVisitor.hpp"

#include "analyzer/detail/analyzers/ClassNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

MixinNodeVisitorResultType MixinNodeVisitor::operator()(const ast::ClassNode& node)
{
    return process(*logger_, *context_, node);
}


}}}