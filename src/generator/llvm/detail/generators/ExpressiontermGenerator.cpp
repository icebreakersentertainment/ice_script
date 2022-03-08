#include "generator/llvm/detail/generators/ExpressiontermGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionvalueGenerator.hpp"
#include "generator/llvm/detail/generators/ExpressionpostoperatorGenerator.hpp"

#include "generator/llvm/detail/visitors/ExpressiontermVisitor.hpp"

#include "generator/llvm/detail/LlvmUtilities.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

using namespace ice_script::asg;

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::Expressionterm& expressionterm)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(expressionterm).name())

    Scope& scope = context.scope();

    ExpressiontermVisitor visitor{logger, context, llvm};
    return boost::get<::llvm::Value*>(boost::apply_visitor(visitor, expressionterm.value));

//    return nullptr;
}

::llvm::Value* process(logger::ILogger& logger, Context& context, Llvm& llvm, const asg::VectorExprpreopExprvalueVectorExprpreopType& vectorExprpreopExprvalueVectorExprpreop)
{
    LOG_DEBUG((&logger), "Processing %s", typeid(vectorExprpreopExprvalueVectorExprpreop).name())

    Scope& scope = context.scope();

    const auto& expressionvalue = boost::get<1>(vectorExprpreopExprvalueVectorExprpreop);
    const auto& expressionpostoperators = boost::get<2>(vectorExprpreopExprvalueVectorExprpreop);

    auto value = process(logger, context, llvm, expressionvalue);

    for (const auto& expressionpostoperator : expressionpostoperators)
    {
        scope.set(value);

        value = process(logger, context, llvm, expressionpostoperator.get());
    }

    return value;

//    return nullptr;
}

}}}}