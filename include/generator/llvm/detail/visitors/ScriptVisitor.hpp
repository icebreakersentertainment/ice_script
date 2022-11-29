#ifndef ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ScriptVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ScriptVisitor : public AbstractVisitor<ScriptVisitor, ScriptVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ScriptVisitorResultType operator()(const asg::Import& import)
    {
        return process(*context_, *llvm_, import);
    }

    ScriptVisitorResultType operator()(const asg::Enumeration& enumeration)
    {
        return process(*context_, *llvm_, enumeration);
    }

    ScriptVisitorResultType operator()(const asg::Typedefinition& typedefinition)
    {
        return process(*context_, *llvm_, typedefinition);
    }

    ScriptVisitorResultType operator()(const asg::Class& class)
    {
        return process(*context_, *llvm_, class);
    }

    ScriptVisitorResultType operator()(const asg::Mixin& mixin)
    {
        return process(*context_, *llvm_, mixin);
    }

    ScriptVisitorResultType operator()(const asg::Interface& interface)
    {
        return process(*context_, *llvm_, interface);
    }

    ScriptVisitorResultType operator()(const asg::Functiondefinition& functiondefinition)
    {
        return process(*context_, *llvm_, functiondefinition);
    }

    ScriptVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
    {
        return process(*context_, *llvm_, virtualproperatorerty);
    }

    ScriptVisitorResultType operator()(const asg::Variable& variable)
    {
        return process(*context_, *llvm_, variable);
    }

    ScriptVisitorResultType operator()(const asg::Function& function)
    {
        return process(*context_, *llvm_, function);
    }

    ScriptVisitorResultType operator()(const asg::Namespace& namespace)
    {
        return process(*context_, *llvm_, namespace);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_SCRIPTVISITOR_HPP
