#include "generator/llvm/detail/visitors/ClassVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/FunctiondefinitionGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ClassVisitorResultType ClassVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

ClassVisitorResultType ClassVisitor::operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
{
    return process(*logger_, *context_, *llvm_, virtualproperatorerty);
}

ClassVisitorResultType ClassVisitor::operator()(const asg::Function& function)
{
    return process(*logger_, *context_, *llvm_, function);
}

ClassVisitorResultType ClassVisitor::operator()(const asg::Variable& variable)
{
    return process(*logger_, *context_, *llvm_, variable);
}

ClassVisitorResultType ClassVisitor::operator()(const asg::Functiondefinition& functiondefinition)
{
    return process(*logger_, *context_, *llvm_, functiondefinition);
}


}}}}