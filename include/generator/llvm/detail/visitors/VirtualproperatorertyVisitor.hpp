#ifndef ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/FunctionattributeGenerator.hpp"
#include "generator/llvm/detail/generators/StatblockGenerator.hpp"

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

    VirtualproperatorertyVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    VirtualproperatorertyVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    VirtualproperatorertyVisitorResultType operator()(const asg::Functionattribute& functionattribute)
    {
        return process(*context_, *llvm_, functionattribute);
    }

    VirtualproperatorertyVisitorResultType operator()(const asg::Statblock& statblock)
    {
        return process(*context_, *llvm_, statblock);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_VIRTUALPROPERATORERTYVISITOR_HPP
