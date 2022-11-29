#ifndef ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/TypeGenerator.hpp"
#include "generator/llvm/detail/generators/IdentifierGenerator.hpp"
#include "generator/llvm/detail/generators/InitlistGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/ArglistGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using VariableVisitorResultType = boost::variant<
        ::llvm::Value*,
        std::vector<::llvm::Value*>
>;

class VariableVisitor : public AbstractVisitor<VariableVisitor, VariableVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    VariableVisitorResultType operator()(const Type& type)
    {
        return process(*context_, *llvm_, type);
    }

    VariableVisitorResultType operator()(const asg::Identifier& identifier)
    {
        return process(*context_, *llvm_, identifier);
    }

    VariableVisitorResultType operator()(const asg::Initlist& initlist)
    {
        return process(*context_, *llvm_, initlist);
    }

    VariableVisitorResultType operator()(const asg::Expression& expression)
    {
        return process(*context_, *llvm_, expression);
    }

    VariableVisitorResultType operator()(const asg::Arglist& arglist)
    {
        return process(*context_, *llvm_, arglist);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_VARIABLEVISITOR_HPP
