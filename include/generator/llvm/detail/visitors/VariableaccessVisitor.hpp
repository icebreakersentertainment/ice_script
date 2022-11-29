#ifndef ICE_SCRIPT_GENERATOR_VARIABLEACCESSVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_VARIABLEACCESSVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using VariableaccessVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class VariableaccessVisitor : public AbstractVisitor<VariableaccessVisitor, VariableaccessVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VariableaccessVisitorResultType operator()(const asg::Scoperatore& scoperatore)
    {
        return process(*context_, *llvm_, scoperatore);
    }

    VariableaccessVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_VARIABLEACCESSVISITOR_HPP
