#ifndef ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionGenerator.hpp"
#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/FunctiondefinitionGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ClassVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ClassVisitor : public AbstractVisitor<ClassVisitor, ClassVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ClassVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    ClassVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
    {
        return process(*context_, *llvm_, virtualproperatorerty);
    }

    ClassVisitorResultType operator()(const asg::Function& function)
    {
        return process(*context_, *llvm_, function);
    }

    ClassVisitorResultType operator()(const asg::Variable& variable)
    {
        return process(*context_, *llvm_, variable);
    }

    ClassVisitorResultType operator()(const asg::Functiondefinition& functiondefinition)
    {
        return process(*context_, *llvm_, functiondefinition);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CLASSVISITOR_HPP
