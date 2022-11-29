#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/SymbolResolver.hpp"

#include "symbol/FunctionSymbol.hpp"

#include "type/OperatorType.hpp"

#include "detail/InsertionOperators.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionterm process(Context& context, const ast::ExprtermNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    const auto& expectedTypes = scope.expectedTypes();

    Expressionterm expressionterm{};

    if (node.value.type() == typeid(ast::ExprpreopsExprvalueExprpostops))
    {
        asg::ExprpreopsExprvalueExprpostops value{};

//        const auto& exprPreopNodes = get<0>(vectorExprpreopExprvalueVectorExprpreop);
//
//        for (const auto& exprPreopNode : exprPreopNodes) astPrinter.operator()(exprPreopNode);
//
//        const auto& exprValueNode = boost::get<1>(vectorExprpreopExprvalueVectorExprpreop);
//
//        astPrinter.operator()(exprValueNode);
//
//        const auto& exprPostopNodes = get<2>(vectorExprpreopExprvalueVectorExprpreop);
//
//        for (const auto& exprPostopNode : exprPostopNodes) astPrinter.operator()(exprPostopNode);



        const auto& exprpreopsExprvalueExprpostops = boost::get<ast::ExprpreopsExprvalueExprpostops>(node.value);

        for (const auto& exprPreopNode : exprpreopsExprvalueExprpostops.exprPreopNodes)
        {
            value.expressionPreoperators.push_back(process(context, exprPreopNode.get()));
        }

//        auto expressionvalue = boost::get<Expressionvalue>(operator()(boost::get<1>(vectorExprpreopExprvalueVectorExprpreop)));

        value.expressionValue = process(context, exprpreopsExprvalueExprpostops.exprValueNode.get());

        context.scope().setValueSymbol(resolveSymbol(context, value.expressionValue));
        context.scope().setValueType(resolveType(context, value.expressionValue));

        for (const auto& exprPostopNode : exprpreopsExprvalueExprpostops.exprPostopNodes)
        {
            value.expressionPostoperators.push_back(process(context, exprPostopNode.get()));
        }

        const auto resolvedType = resolveType(context, value);

        if (!expectedTypes.empty() && std::find(expectedTypes.begin(), expectedTypes.end(), resolvedType) == expectedTypes.end())
        {
            // type is not one of the expected types, so see if there is an implicit conversion operator
            std::shared_ptr<OperatorType> implicitConversionOperator{};

            const auto& operators = resolvedType->operators().find(OperatorTypeId::IMPLICIT_CONVERSION);

            for (const auto& _operator : operators)
            {
                if (std::find(expectedTypes.begin(), expectedTypes.end(), _operator->returnType()) != expectedTypes.end())
                {
                    implicitConversionOperator = _operator;
                    break;
                }
            }

            if (!implicitConversionOperator)
            {
                LOG_ERROR((&context.logger()), "Unable to findByKey implicit conversion operator from %s to %s", resolvedType, expectedTypes)
                throw std::runtime_error("no ic");
            }

            Expressionpostoperator expressionpostoperator{};
            Functioncall functionCall{};

            functionCall.name = implicitConversionOperator->name();
            functionCall.type = implicitConversionOperator;

            expressionpostoperator.value = functionCall;

            value.expressionPostoperators.push_back(expressionpostoperator);
        }

        expressionterm.value = value;

    }
//    else if (initListOrExpressionOrArgList.type() == typeid(asg::ConstructCall))
//    {
//        variable.value = boost::get<asg::ConstructCall>(initListOrExpressionOrArgList);
//    }
//    else
//    {
//        throw std::runtime_error("Invalid result for variable value");
//    }

    return expressionterm;
}

}}}