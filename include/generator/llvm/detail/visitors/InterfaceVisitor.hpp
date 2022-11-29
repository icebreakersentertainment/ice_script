#ifndef ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/InterfacemethodGenerator.hpp"

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

    InterfaceVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    InterfaceVisitorResultType operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
    {
        return process(*context_, *llvm_, virtualproperatorerty);
    }

    InterfaceVisitorResultType operator()(const asg::Interfacemethod& interfacemethod)
    {
        return process(*context_, *llvm_, interfacemethod);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_INTERFACEVISITOR_HPP
