#include "generator/llvm/detail/generators/ExpressionGenerator.hpp"

#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionoperatorertyGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressionVisitor.hpp"

#include "generator/llvm/detail/BinaryOperatorFactory.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expression& expression)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expression).name())

    Scope& scope = context.scope();

//    return operator()(expression.expressionterm);

//    ExpressionVisitor visitor{logger, context, llvm};
//    auto expressionterm = boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expression.expressionterm.get()));
    auto expressionterm = process(logger, context, llvm, expression.expressionterm.get());
//    ::llvm::Value* expressionterm = boost::get<::llvm::Value*>(operator()(expression.expressionterm));

    for (const auto& expressionOperationAndExpressionTerm : expression.expressionOperationsAndExpressionTerms)
    {
//        ::llvm::Value* expressionoperatorerty = boost::get<::llvm::Value*>(operator()(boost::get<0>(expressionOperationAndExpressionTerm)));
//        ::llvm::Value* expressionterm = boost::get<::llvm::Value*>(operator()(boost::get<1>(expressionOperationAndExpressionTerm)));
        BinaryOperatorFactory binaryOperatorFactory = process(logger, context, llvm, boost::get<0>(expressionOperationAndExpressionTerm).get());
        ::llvm::Value* _expressionterm = process(logger, context, llvm, boost::get<1>(expressionOperationAndExpressionTerm).get());

        expressionterm = binaryOperatorFactory.create(expressionterm, _expressionterm);
    }

    return expressionterm;
}

}}}}