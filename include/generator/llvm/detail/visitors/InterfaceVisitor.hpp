#ifndef ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using InterfaceVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class InterfaceVisitor : public AbstractVisitor<InterfaceVisitor, InterfaceVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        InterfaceVisitorResultType operator()(const asg::Identifier& identifier);
    InterfaceVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty);
    InterfaceVisitorResultType operator()(const asg::Interfacemethod& interfacemethod);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP
