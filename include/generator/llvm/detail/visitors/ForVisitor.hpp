#ifndef ICE_SCRIPT_GENERATOR_FORVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_FORVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/VariableGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionstatGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"
#include "generator/llvm/detail/generators/StatementGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ForVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ForVisitor : public AbstractVisitor<ForVisitor, ForVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ForVisitorResultType operator()(const asg::Variable& variable)
    {
        return process(*context_, *llvm_, variable);
    }

    ForVisitorResultType operator()(const asg::Expressionstat& expressionstat)
    {
        return process(*context_, *llvm_, expressionstat);
    }

    ForVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

    ForVisitorResultType operator()(const asg::Statement& statement)
    {
        return process(*context_, *llvm_, statement);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_FORVISITOR_HPP
