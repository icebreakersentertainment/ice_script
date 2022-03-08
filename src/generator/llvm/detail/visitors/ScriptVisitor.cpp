#include "generator/llvm/detail/visitors/ScriptVisitor.hpp"

#include "generator/llvm/detail/generators/ImportGenerator.hpp"
#include "generator/llvm/detail/generators/EnumerationGenerator.hpp"
#include "generator/llvm/detail/generators/TypedefinitionGenerator.hpp"
#include "generator/llvm/detail/generators/ClassGenerator.hpp"
#include "generator/llvm/detail/generators/MixinGenerator.hpp"
#include "generator/llvm/detail/generators/InterfaceGenerator.hpp"
#include "generator/llvm/detail/generators/FunctiondefinitionGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionGenerator.hpp"
#include "generator/llvm/detail/generators/NamespaceGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Import& import)
{
    return process(*logger_, *context_, *llvm_, import);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Enumeration& enumeration)
{
    return process(*logger_, *context_, *llvm_, enumeration);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Typedefinition& typedefinition)
{
    return process(*logger_, *context_, *llvm_, typedefinition);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Class& classData)
{
    return process(*logger_, *context_, *llvm_, classData);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Mixin& mixin)
{
    return process(*logger_, *context_, *llvm_, mixin);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Interface& interfaceData)
{
    return process(*logger_, *context_, *llvm_, interfaceData);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Functiondefinition& functiondefinition)
{
    return process(*logger_, *context_, *llvm_, functiondefinition);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
{
    return process(*logger_, *context_, *llvm_, virtualproperatorerty);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Variable& variable)
{
    return process(*logger_, *context_, *llvm_, variable);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Function& function)
{
    return process(*logger_, *context_, *llvm_, function);
}

ScriptVisitorResultType ScriptVisitor::operator()(const asg::Namespace& namespaceDefinition)
{
    return process(*logger_, *context_, *llvm_, namespaceDefinition);
}


}}}}