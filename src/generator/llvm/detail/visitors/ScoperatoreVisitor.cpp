#include "generator/llvm/detail/visitors/ScoperatoreVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/TypeGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ScoperatoreVisitorResultType ScoperatoreVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ScoperatoreVisitorResultType ScoperatoreVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}


}}}}