#include "generator/llvm/detail/visitors/InterfaceVisitor.hpp"

#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/VirtualproperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/InterfacemethodGenerator.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

InterfaceVisitorResultType InterfaceVisitor::operator()(const asg::Identifier& identifier)
{
    return process(*logger_, *context_, *llvm_, identifier);
}

InterfaceVisitorResultType InterfaceVisitor::operator()(const asg::Virtualproperatorerty& virtualproperatorerty)
{
    return process(*logger_, *context_, *llvm_, virtualproperatorerty);
}

InterfaceVisitorResultType InterfaceVisitor::operator()(const asg::Interfacemethod& interfacemethod)
{
    return process(*logger_, *context_, *llvm_, interfacemethod);
}


}}}}