#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using FunctionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class FunctionVisitor : public AbstractVisitor<FunctionVisitor, FunctionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FunctionVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    FunctionVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    FunctionVisitorResultType operator()(const asg::Parameterlist& parameterlist)
    {
        return process(*context_, *llvm_, parameterlist);
    }

    FunctionVisitorResultType operator()(const asg::Functionattribute& functionattribute)
    {
        return process(*context_, *llvm_, functionattribute);
    }

    FunctionVisitorResultType operator()(const asg::Statblock& statblock)
    {
        return process(*context_, *llvm_, statblock);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONVISITOR_HPP
