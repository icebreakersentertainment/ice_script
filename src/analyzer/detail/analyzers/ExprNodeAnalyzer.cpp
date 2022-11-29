#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"

#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/OperatorTypeUtilities.hpp"
#include "analyzer/detail/ProcessOperatorPrecedence.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "ast/AstPrinter.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

struct ExpressionOperationAndTerm
{
    Expressionoperatorerty expressionOperator;
    Expressionterm expressionTerm;
};

struct OperatorTypeAndExpressionTerm
{
    OperatorTypeAndExpressionTerm(std::shared_ptr<OperatorType> operatorType, Expressionterm expressionTerm)
    :
        operatorType(std::move(operatorType)),
        expressionTerm(std::move(expressionTerm))
    {}

    std::shared_ptr<OperatorType> operatorType;
    Expressionterm expressionTerm;
};

class ExpressionoperatorertyToOperatorTypeIdVisitor : public AbstractVisitor<ExpressionoperatorertyToOperatorTypeIdVisitor, OperatorTypeId>
{
public:
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    OperatorTypeId operator()(const Bitoperator& bitOperator) const
    {
        switch (bitOperator.bitwiseOperator)
        {
            case BitwiseOperator::COMPLEMENT: return OperatorTypeId::BITWISE_COMPLEMENT;
            case BitwiseOperator::LEFT_SHIFT: return OperatorTypeId::BITWISE_LEFT_SHIFT;
            case BitwiseOperator::RIGHT_SHIFT: return OperatorTypeId::BITWISE_RIGHT_SHIFT;
            case BitwiseOperator::ARITHMETIC_RIGHT_SHIFT: return OperatorTypeId::BITWISE_ARITHMETIC_RIGHT_SHIFT; // Do we care to implement this?
            case BitwiseOperator::AND: return OperatorTypeId::BITWISE_AND;
            case BitwiseOperator::XOR: return OperatorTypeId::BITWISE_XOR;
            case BitwiseOperator::OR: return OperatorTypeId::BITWISE_OR;

            default:
                throw InvalidArgumentException("Bitwise operator not valid.");
        }
    }

    OperatorTypeId operator()(const Mathoperator& mathOperator) const
    {
        switch (mathOperator.mathOperator)
        {
            case MathOperator::MULTIPLY: return OperatorTypeId::MULTIPLY;
            case MathOperator::DIVIDE: return OperatorTypeId::DIVIDE;
            case MathOperator::MODULOS: return OperatorTypeId::MODULOS;
            case MathOperator::EXPONENT: return OperatorTypeId::EXPONENT; // Do we care to implement this?
            case MathOperator::ADD: return OperatorTypeId::ADD;
            case MathOperator::SUBTRACT: return OperatorTypeId::SUBTRACT;

            default:
                throw InvalidArgumentException("Math operator not valid.");
        }
    }

    OperatorTypeId operator()(const Comparisonoperator& comparisonOperator) const
    {
        switch (comparisonOperator.comparisonOperator)
        {
            case ComparisonOperator::LESS_THAN: return OperatorTypeId::LESS_THAN;
            case ComparisonOperator::LESS_THAN_OR_EQUALS: return OperatorTypeId::LESS_THAN_OR_EQUALS;
            case ComparisonOperator::GREATER_THAN: return OperatorTypeId::GREATER_THAN;
            case ComparisonOperator::GREATER_THAN_OR_EQUALS: return OperatorTypeId::GREATER_THAN_OR_EQUALS;
            case ComparisonOperator::EQUALS: return OperatorTypeId::EQUALS;
            case ComparisonOperator::NOT_EQUALS: return OperatorTypeId::NOT_EQUALS;
            case ComparisonOperator::IS: return OperatorTypeId::IS; // Do we care to implement this?
            case ComparisonOperator::IS_NOT: return OperatorTypeId::IS_NOT; // Do we care to implement this?

            default:
                throw InvalidArgumentException("Comparison operator not valid.");
        }
    }

    OperatorTypeId operator()(const Logicoperator& logicOperator) const
    {
        switch (logicOperator.logicOperator)
        {
            case LogicOperator::NOT: return OperatorTypeId::NOT;
            case LogicOperator::AND: return OperatorTypeId::AND;
            case LogicOperator::OR: return OperatorTypeId::OR;
            case LogicOperator::XOR: return OperatorTypeId::XOR; // Do we care to implement this?

            default:
                throw InvalidArgumentException("Comparison operator not valid.");
        }
    }
};

OperatorTypeId toOperatorTypeId(Context& context, const Expressionoperatorerty& expressionoperatorerty)
{
    return boost::apply_visitor(ExpressionoperatorertyToOperatorTypeIdVisitor(context), expressionoperatorerty.value);
}

Expressionterm createFunctionCall(Context& context, std::shared_ptr<OperatorType> _operator, const Expressionterm& expressionterm)
{
    Expressionterm result = expressionterm;

    auto& value = boost::get<asg::ExprpreopsExprvalueExprpostops>(result.value);

    Expressionpostoperator expressionpostoperator{};
    Functioncall functionCall{};

    functionCall.name = _operator->name();
    functionCall.type = _operator;

    expressionpostoperator.value = functionCall;

    value.expressionPostoperators.push_back(expressionpostoperator);

    return result;
}

auto translateExpressionOperationsToOperatorTypes(Context& context, const Expressionterm& expressionterm, const std::vector<ExpressionOperationAndTerm>& expressionOperationAndTerms)
{
    Expressionterm expressionTerm{};
    std::vector<OperatorTypeAndExpressionTerm> operatorTypeAndExpressionTerms{};

    Expressionterm lhs = expressionterm;
    std::shared_ptr<Type> lhsType = resolveType(context, expressionterm);

    ICE_SCRIPT_ASSERT(expressionOperationAndTerms.size() < 2)

    for (auto& opAndTerm : expressionOperationAndTerms)
    {
        expressionTerm = opAndTerm.expressionTerm;

        const auto operatorTypeId = toOperatorTypeId(context, opAndTerm.expressionOperator);
        auto rhsType = resolveType(context, opAndTerm.expressionTerm);

        auto operators = context.typeTable().findOperators(operatorTypeId);
        {
            auto _operators = lhsType->operators().find(operatorTypeId);
            operators.insert(operators.end(), _operators.begin(), _operators.end());
        }

        auto filteredOperators = filter(operators, lhsType, rhsType);

        if (filteredOperators.empty())
        {
            // See if we can implicitly convert one of the arguments to match an operator
            auto [newLhs, newRhs, _operator] = implicitlyConvertAndFindOperator(context, operators, lhs, lhsType, opAndTerm.expressionTerm, rhsType, CreateFunctionCallFunction<Expressionterm>(&createFunctionCall));

            if (_operator)
            {
                if (newLhs)
                {
                    lhs = newLhs.get();
                    lhsType = resolveType(context, lhs);
                }
                else if (newRhs)
                {
                    expressionTerm = newRhs.get();
                    rhsType = resolveType(context, expressionTerm);
                }

                filteredOperators.push_back(_operator);
            }
        }

        if (filteredOperators.size() > 1)
        {
            // Ambiguous
            throw RuntimeException("");
        }

        auto& _operator = filteredOperators.back();

        operatorTypeAndExpressionTerms.push_back({_operator, expressionTerm});
    }

    return std::tuple<Expressionterm, std::vector<OperatorTypeAndExpressionTerm>>(lhs, operatorTypeAndExpressionTerms);
}

void applyImplicitConversionOperator(Context& context, Expression& expression, std::shared_ptr<Type> resolvedType, const std::vector<std::shared_ptr<Type>>& expectedTypes)
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

    Expression newExpression{};
    Expressionvalue expressionValue{};
    Assign assign{};

    assign.condition.get().expression = expression;

    expressionValue.value = assign;

    Expressionpostoperator expressionpostoperator{};
    Functioncall functionCall{};

    functionCall.name = implicitConversionOperator->name();
    functionCall.type = implicitConversionOperator;

    expressionpostoperator.value = functionCall;

    newExpression.expressionterm.get().value = asg::ExprpreopsExprvalueExprpostops({}, expressionValue, {expressionpostoperator});

    expression = newExpression;
}

auto wrapAssign(Expressionterm expressionTerm)
{
    Assign assign{};

    assign.condition.get().expression.get().expressionterm = std::move(expressionTerm);

    return assign;
}

auto transformToFunctionCall(Context& context, std::vector<OperatorTypeAndExpressionTerm> operatorTypeAndExpressionTerms)
{
    ICE_SCRIPT_ASSERT(operatorTypeAndExpressionTerms.size() < 2)

    Functioncall functionCall{};

    functionCall.name = operatorTypeAndExpressionTerms[0].operatorType->name();
    functionCall.type = operatorTypeAndExpressionTerms[0].operatorType;
    functionCall.arglist.get().arguments = {Argument("", wrapAssign(operatorTypeAndExpressionTerms[0].expressionTerm))};

    return functionCall;
}

asg::Expression process(Context& context, const ast::ExprNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

//    Expression expression{};

    // ast::AstPrinter printer{std::cout, true};

    // std::cout << "node: " << std::endl;
    // printer(node);

    const ast::ExprNode transformedNode = transformBasedOnOperatorPrecedence(context, node);

    // std::cout << "transformedNode: " << std::endl;
    // printer(transformedNode);

    if (!transformedNode.expropNodeAndExprtermNodes.empty())
    {
        scope.pushExpectedTypes({});
    }
    
    Expressionterm expressionterm = process(context, transformedNode.exprtermNode.get());
    std::vector<ExpressionOperationAndTerm> expressionOperationAndTerms{};

    for (const auto& expropNodeAndExprtermNode : transformedNode.expropNodeAndExprtermNodes)
    {
        ExpressionOperationAndTerm opAndTerm{};

        opAndTerm.expressionOperator = process(context, expropNodeAndExprtermNode.expropNode.get());
        opAndTerm.expressionTerm = process(context, expropNodeAndExprtermNode.exprtermNode.get());

        expressionOperationAndTerms.push_back(opAndTerm);
    }

    Expression expression{};
    std::vector<OperatorTypeAndExpressionTerm> operatorTypeAndExpressionTerms{};

    std::tie(expression.expressionterm, operatorTypeAndExpressionTerms) = translateExpressionOperationsToOperatorTypes(context, expressionterm, expressionOperationAndTerms);

    if (!transformedNode.expropNodeAndExprtermNodes.empty())
    {
        scope.popExpectedTypes();

        expression.functioncall = {transformToFunctionCall(context, operatorTypeAndExpressionTerms)};

        const auto expectedTypes = scope.expectedTypes();

        if (!expectedTypes.empty())
        {
            const auto resolvedType = resolveType(context, expression);

            if (std::find(expectedTypes.begin(), expectedTypes.end(), resolvedType) == expectedTypes.end())
            {
                applyImplicitConversionOperator(context, expression, resolvedType, expectedTypes);
            }
        }
    }

    return expression;
}

}}}