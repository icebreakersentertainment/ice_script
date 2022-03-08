#include "generator/llvm/detail/visitors/FunctiondefinitionVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

FunctiondefinitionVisitorResultType FunctiondefinitionVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

FunctiondefinitionVisitorResultType FunctiondefinitionVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

FunctiondefinitionVisitorResultType FunctiondefinitionVisitor::operator()(const asg::Parameterlist& parameterlist)
{
    return process(*logger_, *context_, *llvm_, parameterlist);
}


}}}}