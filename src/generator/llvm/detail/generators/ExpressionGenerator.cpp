#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"
#include "generator/llvm/detail/generators/FunctioncallGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionVisitor.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Expression& expression)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expression).name())

    Scope& scope = context.scope();

    auto expressionterm = process(context, llvm, expression.expressionterm.get());

    if (expression.functioncall)
    {
        scope.set(expressionterm);

        expressionterm = process(context, llvm, expression.functioncall.get().get());
    }

//    for (const auto& operatorTypeAndExpressionTerm : expression.operatorTypeAndExpressionTerms)
//    {
////        ::llvm::Value* expressionoperatorerty = boost::get<::llvm::Value*>(operator()(boost::get<0>(expressionOperationAndExpressionTerm)));
////        ::llvm::Value* expressionterm = boost::get<::llvm::Value*>(operator()(boost::get<1>(expressionOperationAndExpressionTerm)));
//
////        BinaryOperatorFactory binaryOperatorFactory = process(context, llvm, operatorTypeAndExpressionTerm.operatorType);
////        ::llvm::Value* _expressionterm = process(context, llvm, operatorTypeAndExpressionTerm.expressionTerm.get());
////
////        expressionterm = binaryOperatorFactory.create(expressionterm, _expressionterm);
//    }

    return expressionterm;
}

}}}}