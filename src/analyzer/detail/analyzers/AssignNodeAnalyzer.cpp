#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignopNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ConditionNodeAnalyzer.hpp"

#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/OperatorTypeUtilities.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

Assign createFunctionCall(Context& context, std::shared_ptr<OperatorType> _operator, const Assign& assign)
{
    Assign result{};// = assign;

    asg::ExprpreopsExprvalueExprpostops value{};

    Expressionpostoperator expressionpostoperator{};
    Functioncall functionCall{};

    functionCall.name = _operator->name();
    functionCall.type = _operator;

    expressionpostoperator.value = functionCall;

    value.expressionValue.value = assign;

    value.expressionPostoperators.push_back(expressionpostoperator);

    result.condition.get().expression.get().expressionterm.get().value = value;

    return result;
}

auto translateAssignOperationToOperatorType(Context& context, const Assign& lhs, const std::shared_ptr<Type>& lhsType, const Assignoperator& assignOperator, const Assign& rhs)
{
    const auto operatorTypeId = toOperatorTypeId(context, assignOperator);
    auto newRhs = rhs;
    auto rhsType = resolveType(context, rhs);

    auto operators = context.typeTable().findOperators(operatorTypeId);
    {
        auto _operators = lhsType->operators().find(operatorTypeId);
        operators.insert(operators.end(), _operators.begin(), _operators.end());
    }

    auto filteredOperators = filter(operators, lhsType, rhsType);

    if (filteredOperators.empty())
    {
        // See if we can implicitly convert one of the arguments to match an operator
        auto [_, _newRhs, _operator] = implicitlyConvertAndFindOperator(context, operators, lhs, lhsType, false, rhs, rhsType, true, CreateFunctionCallFunction<Assign>(&createFunctionCall));

        if (_operator)
        {
            if (_newRhs)
            {
                newRhs = _newRhs.get();
//                rhsType = resolveType(context, newRhs);

                filteredOperators.push_back(_operator);
            }
        }
    }

    if (filteredOperators.size() > 1)
    {
        // Ambiguous
        throw RuntimeException("");
    }

    auto& _operator = filteredOperators.back();

    return std::tuple<Assign, std::shared_ptr<OperatorType>, Assign>(lhs, _operator, newRhs);
}

auto transformToFunctionCall(Context& context, std::shared_ptr<OperatorType> operatorType, Assign assign)
{
    Functioncall functionCall{};

    functionCall.name = operatorType->name();
    functionCall.type = operatorType;
    functionCall.arglist.get().arguments = {Argument("", assign)};

    return functionCall;
}

asg::Assign process(Context& context, const ast::AssignNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Assign assign{};

    assign.condition = process(context, node.conditionNode.get());

    if (node.assignopAssignNode)
    {
        auto resolvedType = resolveType(context, assign.condition.get());

        auto assignOperator = process(context, node.assignopAssignNode.get().assignopNode.get());
        
        const auto operatorTypeId = toOperatorTypeId(context, assignOperator);
        
        const auto operators = resolvedType->operators().find(operatorTypeId);
        
        std::vector<std::shared_ptr<Type>> expectedTypes{};
        
        // TODO remove duplicates
        for (const auto& _operator : operators)
        {
            for (const auto& parameter : _operator->parameters()) expectedTypes.push_back(parameter);
        }
        
        expectedTypes.push_back(resolvedType);
        
        scope.pushExpectedTypes(expectedTypes);
        
        auto rhsAssign = process(context, node.assignopAssignNode.get().assignNode.get());
//        assign.functioncall = process(context, node.assignopAssignNode.get());

//        auto operatorType = translateAssignOperationToOperatorType(context, assign, assignOperator, rhsAssign);
        auto [newLhs, operatorType, newRhs] = translateAssignOperationToOperatorType(context, assign, resolvedType, assignOperator, rhsAssign);

        assign.functioncall = {transformToFunctionCall(context, operatorType, newRhs)};

        scope.popExpectedTypes();
    }

    return assign;
}

}}}