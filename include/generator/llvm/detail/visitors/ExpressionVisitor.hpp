#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONVISITOR_HPP

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using ExpressionVisitorResultType = boost::variant<
        ::llvm::Value*,
        BinaryOperatorFactory
>;

class ExpressionVisitor : public AbstractVisitor<ExpressionVisitor, ExpressionVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExpressionVisitorResultType operator()(const asg::Expressionterm& expressionterm)
    {
        return process(*context_, *llvm_, expressionterm);
    }

    ExpressionVisitorResultType operator()(const asg::Expressionoperatorerty& expressionoperatorerty)
    {
        return process(*context_, *llvm_, expressionoperatorerty);
    }

};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONVISITOR_HPP
