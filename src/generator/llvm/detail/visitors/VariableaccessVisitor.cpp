#include "generator/llvm/detail/visitors/VariableaccessVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

VariableaccessVisitorResultType VariableaccessVisitor::operator()(const asg::Scoperatore& scoperatore)
{
    return process(*logger_, *context_, *llvm_, scoperatore);
}

VariableaccessVisitorResultType VariableaccessVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}


}}}}