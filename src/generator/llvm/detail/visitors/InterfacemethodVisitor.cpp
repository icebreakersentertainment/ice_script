#include "generator/llvm/detail/visitors/InterfacemethodVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

InterfacemethodVisitorResultType InterfacemethodVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

InterfacemethodVisitorResultType InterfacemethodVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

InterfacemethodVisitorResultType InterfacemethodVisitor::operator()(const asg::Parameterlist& parameterlist)
{
    return process(*logger_, *context_, *llvm_, parameterlist);
}


}}}}