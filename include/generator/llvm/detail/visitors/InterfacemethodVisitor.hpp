#ifndef ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

        InterfacemethodVisitorResultType operator()(const asg::Type& type);
    InterfacemethodVisitorResultType operator()(const asg::Identifier& identifier);
    InterfacemethodVisitorResultType operator()(const asg::Parameterlist& parameterlist);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_INTERFACEMETHODVISITOR_HPP
