#ifndef ICE_SCRIPT_GENERATOR_CONDITIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_CONDITIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"
#include "generator/llvm/detail/generators/AssignGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ConditionVisitorResultType = boost::variant<
        ::llvm::Value*
>;

class ConditionVisitor : public AbstractVisitor<ConditionVisitor, ConditionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ConditionVisitorResultType operator()(const asg::Expression& expression)
    {
        return process(*context_, *llvm_, expression);
    }

    ConditionVisitorResultType operator()(const asg::Assign& assign)
    {
        return process(*context_, *llvm_, assign);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_CONDITIONVISITOR_HPP
