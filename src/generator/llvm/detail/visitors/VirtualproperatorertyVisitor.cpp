#include "generator/llvm/detail/visitors/VirtualproperatorertyVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

VirtualproperatorertyVisitorResultType VirtualproperatorertyVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

VirtualproperatorertyVisitorResultType VirtualproperatorertyVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

VirtualproperatorertyVisitorResultType VirtualproperatorertyVisitor::operator()(const asg::Functionattribute& functionattribute)
{
    return process(*logger_, *context_, *llvm_, functionattribute);
}

VirtualproperatorertyVisitorResultType VirtualproperatorertyVisitor::operator()(const asg::Statblock& statblock)
{
    return process(*logger_, *context_, *llvm_, statblock);
}


}}}}