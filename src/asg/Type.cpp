#include "asg/Type.hpp"

#include "asg/OperatorType.hpp"

namespace ice_script { namespace asg {

std::vector<std::shared_ptr<OperatorType>> Type::findOperators(const OperatorTypeId operatorTypeId)
{
    std::vector<std::shared_ptr<OperatorType>> operators{};

    std::copy_if(operators_.begin(), operators_.end(), std::back_inserter(operators), [=](const auto& _operator) {
        return _operator->operatorTypeId() == operatorTypeId;
    });

    return operators;
}

void Type::setOperators(std::vector<std::shared_ptr<OperatorType>> operators)
{
    operators_ = std::move(operators);
}

}}