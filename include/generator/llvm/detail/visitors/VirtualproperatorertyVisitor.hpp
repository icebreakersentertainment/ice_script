#ifndef ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using VirtualproperatorertyVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class VirtualproperatorertyVisitor : public AbstractVisitor<VirtualproperatorertyVisitor, VirtualproperatorertyVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

        VirtualproperatorertyVisitorResultType operator()(const asg::Type& type);
    VirtualproperatorertyVisitorResultType operator()(const asg::Identifier& identifier);
    VirtualproperatorertyVisitorResultType operator()(const asg::Functionattribute& functionattribute);
    VirtualproperatorertyVisitorResultType operator()(const asg::Statblock& statblock);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP
