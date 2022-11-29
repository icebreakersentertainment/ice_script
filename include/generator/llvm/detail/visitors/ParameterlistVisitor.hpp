#ifndef ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/TypemodifierGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ParameterlistVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ParameterlistVisitor : public AbstractVisitor<ParameterlistVisitor, ParameterlistVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ParameterlistVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    ParameterlistVisitorResultType operator()(const asg::Typemodifier& typemodifier)
    {
        return process(*context_, *llvm_, typemodifier);
    }

    ParameterlistVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    ParameterlistVisitorResultType operator()(const asg::Expression& expression)
    {
        return process(*context_, *llvm_, expression);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_PARAMETERLISTVISITOR_HPP
