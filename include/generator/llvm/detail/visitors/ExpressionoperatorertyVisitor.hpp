#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "detail/Assert.hpp"
#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

#include "generator/llvm/detail/generators/MathoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/ComparisonoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/LogicoperatorGenerator.hpp"
#include "generator/llvm/detail/generators/BitoperatorGenerator.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

//using ExpressionoperatorertyVisitorResultType = boost::variant<
//        ::llvm::Value*,
//        BinaryOperatorFactory
//>;

using ExpressionoperatorertyVisitorResultType = BinaryOperatorFactory;

class ExpressionoperatorertyVisitor : public AbstractVisitor<ExpressionoperatorertyVisitor, ExpressionoperatorertyVisitorResultType>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    ExpressionoperatorertyVisitorResultType operator()(const monostate& node)
    {
        ICE_SCRIPT_ASSERT(false);
        
        return BinaryOperatorFactory(*context_, *llvm_);
    }

    ExpressionoperatorertyVisitorResultType operator()(const asg::Mathoperator& mathoperator)
    {
        return process(*context_, *llvm_, mathoperator);
    }

    ExpressionoperatorertyVisitorResultType operator()(const asg::Comparisonoperator& comparisonoperator)
    {
        return process(*context_, *llvm_, comparisonoperator);
    }

    ExpressionoperatorertyVisitorResultType operator()(const asg::Logicoperator& logicoperator)
    {
        return process(*context_, *llvm_, logicoperator);
    }

    ExpressionoperatorertyVisitorResultType operator()(const asg::Bitoperator& bitoperator)
    {
        return process(*context_, *llvm_, bitoperator);
    }
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP
