#ifndef ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using InterfacemethodVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class InterfacemethodVisitor : public AbstractVisitor<InterfacemethodVisitor, InterfacemethodVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    InterfacemethodVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    InterfacemethodVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    InterfacemethodVisitorResultType operator()(const asg::Parameterlist& parameterlist)
    {
        return process(*context_, *llvm_, parameterlist);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP
