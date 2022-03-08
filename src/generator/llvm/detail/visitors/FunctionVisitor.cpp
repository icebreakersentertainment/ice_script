#include "generator/llvm/detail/visitors/FunctionVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

FunctionVisitorResultType FunctionVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

FunctionVisitorResultType FunctionVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

FunctionVisitorResultType FunctionVisitor::operator()(const asg::Parameterlist& parameterlist)
{
    return process(*logger_, *context_, *llvm_, parameterlist);
}

FunctionVisitorResultType FunctionVisitor::operator()(const asg::Functionattribute& functionattribute)
{
    return process(*logger_, *context_, *llvm_, functionattribute);
}

FunctionVisitorResultType FunctionVisitor::operator()(const asg::Statblock& statblock)
{
    return process(*logger_, *context_, *llvm_, statblock);
}


}}}}