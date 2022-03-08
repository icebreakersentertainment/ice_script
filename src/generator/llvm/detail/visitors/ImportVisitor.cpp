#include "generator/llvm/detail/visitors/ImportVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StringGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ImportVisitorResultType ImportVisitor::operator()(const asg::Type& type)
{
    return process(*logger_, *context_, *llvm_, type);
}

ImportVisitorResultType ImportVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ImportVisitorResultType ImportVisitor::operator()(const asg::Parameterlist& parameterlist)
{
    return process(*logger_, *context_, *llvm_, parameterlist);
}

ImportVisitorResultType ImportVisitor::operator()(const asg::Functionattribute& functionattribute)
{
    return process(*logger_, *context_, *llvm_, functionattribute);
}

ImportVisitorResultType ImportVisitor::operator()(const asg::String& string)
{
    return process(*logger_, *context_, *llvm_, string);
}


}}}}