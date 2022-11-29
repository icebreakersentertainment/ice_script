#include "analyzer/detail/OperatorTypeUtilities.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace asg;

std::shared_ptr<OperatorType> findBestMatchImplicitConversionOperator(const std::shared_ptr<Type>& fromType, const std::shared_ptr<Type>& toType)
{
    const auto& operators = fromType->operators().find(OperatorTypeId::IMPLICIT_CONVERSION);

    auto it = std::find_if(operators.begin(), operators.end(), [&](const auto& _operator) { return _operator->returnType() == toType; });

    if (it != operators.end()) return *it;

    return nullptr;
}

std::vector<std::shared_ptr<OperatorType>> filter(const std::vector<std::shared_ptr<OperatorType>>& operators, const std::shared_ptr<Type>& type1,
       const std::shared_ptr<Type>& type2)
{
    std::vector <std::shared_ptr<OperatorType>> result{};

    for (const auto& _operator: operators)
    {
        const auto& parameters = _operator->parameters();

        if (parameters.size() == 1)
        {
            if (!_operator->isMethod()) continue;

            const auto& owner = _operator->ownerType();
            const auto& parameter = parameters[0];

            if (owner == type1 && parameter == type2) result.push_back(_operator);
        }
        else if (parameters.size() == 2)
        {
            if (_operator->isMethod()) continue;

            const auto& parameter1 = parameters[0];
            const auto& parameter2 = parameters[1];

            if (parameter1 == type1 && parameter2 == type2) result.push_back(_operator);
        }
    }

    return result;
}

}}}