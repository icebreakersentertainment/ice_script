#ifndef ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP
#define ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP

#include <string>

#include "asg/Asg.hpp"

#include "generator/llvm/detail/visitors/AbstractVisitor.hpp"

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

    ExpressionoperatorertyVisitorResultType operator()(const asg::Mathoperator& mathoperator);
    ExpressionoperatorertyVisitorResultType operator()(const asg::Comparisonoperator& comparisonoperator);
    ExpressionoperatorertyVisitorResultType operator()(const asg::Logicoperator& logicoperator);
    ExpressionoperatorertyVisitorResultType operator()(const asg::Bitoperator& bitoperator);
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_EXPRESSIONOPERATORERTYVISITOR_HPP
