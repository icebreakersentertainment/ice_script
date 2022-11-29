#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONCALLVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONCALLVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ScoperatoreGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using FunctioncallVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class FunctioncallVisitor : public AbstractVisitor<FunctioncallVisitor, FunctioncallVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FunctioncallVisitorResultType operator()(const asg::Scoperatore& scoperatore)
    {
        return process(*context_, *llvm_, scoperatore);
    }

    FunctioncallVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    FunctioncallVisitorResultType operator()(const asg::Arglist& arglist)
    {
        return process(*context_, *llvm_, arglist);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONCALLVISITOR_HPP
