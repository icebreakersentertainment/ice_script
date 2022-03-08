#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

#include "analyzer/detail/TypeResolver.hpp"

#include "analyzer/FunctionSymbol.hpp"

#include "asg/OperatorType.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionterm process(logger::ILogger& logger, Context& context, const ast::ExprtermNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    const std::vector<std::shared_ptr<Type>>& expectedTypes = scope.expectedTypes();

    Expressionterm expressionterm{};

    if (node.value.type() == typeid(ast::VectorExprpreopExprvalueVectorExprpreopType))
    {
        asg::VectorExprpreopExprvalueVectorExprpreopType value{};

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



        const auto& vectorExprpreopExprvalueVectorExprpreop = boost::get<ast::VectorExprpreopExprvalueVectorExprpreopType>(node.value);

        const auto& exprPreopNodes = boost::get<0>(vectorExprpreopExprvalueVectorExprpreop);

        for (const auto& exprPreopNode : exprPreopNodes)
        {
            boost::get<0>(value).push_back(process(logger, context, exprPreopNode.get()));
        }

//        auto expressionvalue = boost::get<Expressionvalue>(operator()(boost::get<1>(vectorExprpreopExprvalueVectorExprpreop)));
        const auto& exprvalueNode = boost::get<1>(vectorExprpreopExprvalueVectorExprpreop);

        auto expressionvalue = process(logger, context, exprvalueNode.get());

        const auto& exprPostopNodes = boost::get<2>(vectorExprpreopExprvalueVectorExprpreop);

        for (const auto& exprPostopNode : exprPostopNodes)
        {
            boost::get<2>(value).push_back(process(logger, context, exprPostopNode.get()));
        }

        boost::get<1>(value) = expressionvalue;

        std::shared_ptr<Type> resolvedType{};

        if (!boost::get<2>(value).empty())
        {
            resolvedType = resolveType(logger, context, boost::get<2>(value).back().get());
        }
        else
        {
            resolvedType = resolveType(logger, context, expressionvalue);
        }

        if (std::find(expectedTypes.begin(), expectedTypes.end(), resolvedType) == expectedTypes.end())
        {
            // type is not one of the expected types, so see if there is an implicit conversion operator
            std::shared_ptr<OperatorType> implicitConversionOperator{};

            const auto& operators = resolvedType->findOperators(OperatorTypeId::IMPLICIT_CONVERSION);

            for (const auto& _operator : operators)
            {
                if (std::find(expectedTypes.begin(), expectedTypes.end(), _operator->returnType()) != expectedTypes.end())
                {
                    implicitConversionOperator = _operator;
                    break;
                }
            }

            if (!implicitConversionOperator) throw std::runtime_error("no ic");

            Expressionpostoperator expressionpostoperator{};
            Functioncall functionCall{};

//            functionCall.name = implicitConversionOperator->name();
//
//            expressionpostoperator.value = functionCall;

            boost::get<2>(value).push_back(expressionpostoperator);
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