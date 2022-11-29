#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressiontermVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(Context& context, Llvm& llvm, const asg::Expressionterm& expressionterm)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(expressionterm).name())

    Scope& scope = context.scope();

    ExpressiontermVisitor visitor{context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expressionterm.value));

//    return nullptr;
}

::llvm::Value* process(Context& context, Llvm& llvm, const asg::ExprpreopsExprvalueExprpostops& exprpreopsExprvalueExprpostops)
{
    LOG_DEBUG((&context.logger()), "Processing %s", typeid(exprpreopsExprvalueExprpostops).name())

    Scope& scope = context.scope();

//    const auto& expressionvalue = exprpreopsExprvalueExprpostops.expressionValue;
//    const auto& expressionpostoperators = exprpreopsExprvalueExprpostops.expressionPostoperators;
//
//    if (expressionvalue.value.which() == 2)
//    {
//        auto v = boost::get<Functioncall>(expressionvalue.value);
//
//    }

    auto value = process(context, llvm, exprpreopsExprvalueExprpostops.expressionValue);

    for (const auto& expressionpostoperator : exprpreopsExprvalueExprpostops.expressionPostoperators)
    {
        scope.set(value);

        value = process(context, llvm, expressionpostoperator.get());
    }
    
    scope.set(static_cast<::llvm::Value*>(nullptr));

    return value;

//    return nullptr;
}

}}}}