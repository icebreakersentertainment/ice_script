#include "generator/llvm/detail/visitors/DatatypeVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/PrimativetypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

DatatypeVisitorResultType DatatypeVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

DatatypeVisitorResultType DatatypeVisitor::operator()(const asg::Primativetype& primativetype)
{
    return process(*logger_, *context_, *llvm_, primativetype);
}


}}}}