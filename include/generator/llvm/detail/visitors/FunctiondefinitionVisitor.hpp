#ifndef ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/ParameterlistGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using FunctiondefinitionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class FunctiondefinitionVisitor : public AbstractVisitor<FunctiondefinitionVisitor, FunctiondefinitionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    FunctiondefinitionVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    FunctiondefinitionVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    FunctiondefinitionVisitorResultType operator()(const asg::Parameterlist& parameterlist)
    {
        return process(*context_, *llvm_, parameterlist);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FUNCTIONDEFINITIONVISITOR_HPP
