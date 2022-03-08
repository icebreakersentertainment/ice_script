#include "generator/llvm/detail/visitors/TypedefinitionVisitor.hpp"

#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

TypedefinitionVisitorResultType TypedefinitionVisitor::operator()(const asg::Primativetype& primativetype)
{
    return process(*logger_, *context_, *llvm_, primativetype);
}

TypedefinitionVisitorResultType TypedefinitionVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}


}}}}