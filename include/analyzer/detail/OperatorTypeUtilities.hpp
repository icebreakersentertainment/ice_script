#ifndef ICE_SCRIPT_OPERATORTYPEUTILITIES_HPP
#define ICE_SCRIPT_OPERATORTYPEUTILITIES_HPP

#include <functional>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>

#include "analyzer/detail/Context.hpp"

#include "ast/PostfixOperator.hpp"

#include "type/OperatorType.hpp"
#include "asg/Assignoperator.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

inline OperatorTypeId toOperatorTypeId(Context& context, const ast::PostfixOperator& postfixOperator)
{
    switch (postfixOperator)
    {
        case ast::PostfixOperator::INCREMENT: return OperatorTypeId::POSTFIX_INCREMENT;
        case ast::PostfixOperator::DECREMENT: return OperatorTypeId::POSTFIX_DECREMENT;

        default:
            throw InvalidArgumentException("Postfix operator not valid.");
    }
}

inline OperatorTypeId toOperatorTypeId(Context& context, const asg::Assignoperator& assignOperator)
{
    switch (assignOperator.assignOperator)
    {

        case ast::AssignOperator::EQUAL: return OperatorTypeId::ASSIGN_EQUAL;
        case ast::AssignOperator::ADD: return OperatorTypeId::ASSIGN_ADD;
        case ast::AssignOperator::SUBTRACT: return OperatorTypeId::ASSIGN_SUBTRACT;
        case ast::AssignOperator::MULTIPLY: return OperatorTypeId::ASSIGN_MULTIPLY;
        case ast::AssignOperator::DIVIDE: return OperatorTypeId::ASSIGN_DIVIDE;
        case ast::AssignOperator::MODULOS: return OperatorTypeId::ASSIGN_MODULOS;
        case ast::AssignOperator::EXPONENT: return OperatorTypeId::ASSIGN_EXPONENT;
        case ast::AssignOperator::AND: return OperatorTypeId::ASSIGN_AND;
        case ast::AssignOperator::OR: return OperatorTypeId::ASSIGN_OR;
        case ast::AssignOperator::XOR: return OperatorTypeId::ASSIGN_XOR; // Do we care to implement this?
        case ast::AssignOperator::LEFT_SHIFT: return OperatorTypeId::ASSIGN_LEFT_SHIFT;
        case ast::AssignOperator::RIGHT_SHIFT: return OperatorTypeId::ASSIGN_RIGHT_SHIFT;
        case ast::AssignOperator::ARITHMETIC_RIGHT_SHIFT: return OperatorTypeId::ASSIGN_ARITHMETIC_RIGHT_SHIFT;

        default:
            throw InvalidArgumentException("Assign operator not valid.");
    }
}

/**
 * A number representing the priority of a type for promotion purposes.
 *
 * The higher the number, the higher the priority.
 *
 * @param type
 * @return
 */
inline uint32_t conversionIndex(const std::shared_ptr<Type>& type)
{
    switch (type->typeId())
    {
        case Type::TypeId::VOID_T: return 1000;

        case Type::TypeId::DOUBLE: return 999;
        case Type::TypeId::FLOAT: return 998;

        case Type::TypeId::INTEGER64: return 997;
        case Type::TypeId::UINTEGER64: return 996;
        case Type::TypeId::INTEGER: return 995;
        case Type::TypeId::INTEGER32: return 995;
        case Type::TypeId::UINTEGER: return 994;
        case Type::TypeId::UINTEGER32: return 994;
        case Type::TypeId::INTEGER16: return 993;
        case Type::TypeId::UINTEGER16: return 992;
        case Type::TypeId::INTEGER8: return 991;
        case Type::TypeId::UINTEGER8: return 990;

        case Type::TypeId::BOOLEAN: return 989;

        case Type::TypeId::FUNCTION: return 988;
        case Type::TypeId::OPERATOR: return 987;
    }

    return 0;
}

std::shared_ptr<OperatorType> findBestMatchImplicitConversionOperator(const std::shared_ptr<Type>& fromType, const std::shared_ptr<Type>& toType);

std::vector<std::shared_ptr<OperatorType>> filter(const std::vector<std::shared_ptr<ice_script::OperatorType>>& operators, const std::shared_ptr<Type>& type1, const std::shared_ptr<Type>& type2);

template <typename T>
using CreateFunctionCallFunction = std::function<T(Context&, std::shared_ptr<OperatorType>, const T&)>;

template <typename T>
inline auto implicitlyConvertAndFindOperator(Context& context,
                                      const std::vector<std::shared_ptr<OperatorType>>& operators,
                                      const T& lhs, const std::shared_ptr<Type>& lhsType, bool lhsAllowImplicitConversion,
                                      const T& rhs, const std::shared_ptr<Type>& rhsType, bool rhsAllowImplicitConversion,
                                      const CreateFunctionCallFunction<T>& createFunctionCallFunction)
{
//    boost::optional<Expressionterm> newLhs{};
//    boost::optional<Expressionterm> newRhs{};
//    std::shared_ptr<OperatorType> resultingOperator{};

    if (!lhsAllowImplicitConversion && !rhsAllowImplicitConversion)
    {
        throw InvalidArgumentException("Must allow at least one of left hand side or right hand side to be implicitly converted.");
    }

    // Primitives
    if (lhsType->primitive() && rhsType->primitive())
    {
        boost::optional<T> newLhs{};
        boost::optional<T> newRhs{};
        std::shared_ptr<Type> resultingType{};

        // i.e. int32 > int16
        if (rhsAllowImplicitConversion && conversionIndex(lhsType) > conversionIndex(rhsType))
        {
            auto implicitConversionOperator = findBestMatchImplicitConversionOperator(rhsType, lhsType);

            ICE_SCRIPT_ASSERT(implicitConversionOperator)

            resultingType = lhsType;
//            newRhs = createImplicitConversion(context, rhs, lhsType);
            newRhs = createFunctionCallFunction(context, implicitConversionOperator, rhs);
        }
        // i.e. int32 < float
        else if (lhsAllowImplicitConversion)
        {
            auto implicitConversionOperator = findBestMatchImplicitConversionOperator(lhsType, rhsType);

            ICE_SCRIPT_ASSERT(implicitConversionOperator)

            resultingType = rhsType;
//            newLhs = createImplicitConversion(context, lhs, rhsType);
            newLhs = createFunctionCallFunction(context, implicitConversionOperator, lhs);
        }

        auto _operators = filter(operators, resultingType, resultingType);

        if (_operators.empty())
        {
            _operators = resultingType->operators().find(operators[0]->operatorTypeId());
            _operators = filter(_operators, resultingType, resultingType);
        }

        std::shared_ptr<OperatorType> resultingOperator = !_operators.empty() ? _operators[0] : nullptr;

        return std::tuple<
                    boost::optional<T>,
                    boost::optional<T>,
                    std::shared_ptr<OperatorType>
            >(newLhs, newRhs, resultingOperator);
    }

    for (const auto& _operator : operators)
    {
        const auto& parameters = _operator->parameters();

        if (parameters.empty() || parameters.size() > 2) continue;

        if (parameters.size() == 1 && !_operator->isMethod()) continue;
        if (parameters.size() == 2 && _operator->isMethod()) continue;

        const auto& ownerOrParameterType1 = _operator->ownerType() ? _operator->ownerType() : parameters[0];
        const auto& parameterType2 = parameters[_operator->ownerType() ? 0 : 1];

        // i.e. A.operator(B) where lhs = A
        if (rhsAllowImplicitConversion && ownerOrParameterType1 == lhsType)
        {
            if (auto implicitConversionOperator = findBestMatchImplicitConversionOperator(rhsType, parameterType2))
            {
                auto newRhs = createFunctionCallFunction(context, implicitConversionOperator, rhs);

                return std::tuple<
                        boost::optional<T>,
                        boost::optional<T>,
                        std::shared_ptr<OperatorType>
                >({}, newRhs, _operator);
            }
        }
        // i.e. A.operator(B) where rhs = B
        else if (lhsAllowImplicitConversion && parameterType2 == rhsType)
        {
            if (auto implicitConversionOperator = findBestMatchImplicitConversionOperator(lhsType, ownerOrParameterType1))
            {
                auto newLhs = createFunctionCallFunction(context, implicitConversionOperator, lhs);

                return std::tuple<
                        boost::optional<T>,
                        boost::optional<T>,
                        std::shared_ptr<OperatorType>
                >(newLhs, {}, _operator);
            }
        }
        // i.e. A.operator(B) where neither match
        else if (lhsAllowImplicitConversion && rhsAllowImplicitConversion)
        {
            auto implicitConversionOperatorLhs = findBestMatchImplicitConversionOperator(lhsType, ownerOrParameterType1);
            auto implicitConversionOperatorRhs = findBestMatchImplicitConversionOperator(rhsType, parameterType2);

            if (implicitConversionOperatorLhs && implicitConversionOperatorRhs)
            {
                auto newLhs = createFunctionCallFunction(context, implicitConversionOperatorLhs, lhs);
                auto newRhs = createFunctionCallFunction(context, implicitConversionOperatorRhs, rhs);

                return std::tuple<
                        boost::optional<T>,
                        boost::optional<T>,
                        std::shared_ptr<OperatorType>
                >(newLhs, newRhs, _operator);
            }
        }
    }

    return std::tuple<
                    boost::optional<T>,
                    boost::optional<T>,
                    std::shared_ptr<OperatorType>
            >({}, {}, nullptr);
}

template <typename T>
inline auto implicitlyConvertAndFindOperator(Context& context,
                                      const std::vector<std::shared_ptr<OperatorType>>& operators,
                                      const T& lhs, const std::shared_ptr<Type>& lhsType,
                                      const T& rhs, const std::shared_ptr<Type>& rhsType,
                                      const CreateFunctionCallFunction<T>& createFunctionCallFunction)
{
    return implicitlyConvertAndFindOperator(context, operators, lhs, lhsType, true, rhs, rhsType, true, createFunctionCallFunction);
}

}}}

#endif //ICE_SCRIPT_OPERATORTYPEUTILITIES_HPP
