#include "generator/llvm/detail/visitors/ParameterlistVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ParameterlistVisitorResultType ParameterlistVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

ParameterlistVisitorResultType ParameterlistVisitor::operator()(const asg::Typemodifier& typemodifier)
{
    return process(*logger_, *context_, *llvm_, typemodifier);
}

ParameterlistVisitorResultType ParameterlistVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ParameterlistVisitorResultType ParameterlistVisitor::operator()(const asg::Expression& expression)
{
    return process(*logger_, *context_, *llvm_, expression);
}


}}}}