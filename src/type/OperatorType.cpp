#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "type/OperatorType.hpp"

namespace ice_script
{

OperatorType::OperatorType(const OperatorTypeId operatorTypeId) : FunctionType(), operatorTypeId_(operatorTypeId)
{
    typeId_ = Type::TypeId::OPERATOR;
    name_ = toString(typeId_) + toString(operatorTypeId_);
}

std::string toOperatorTypeKey(const OperatorType& operatorType)
{
    const auto parameterTypeKeys = operatorType.parameters()
        | ranges::views::transform([&](const auto& parameterType) { return parameterType->key(); })
        | ranges::to<std::vector>()
        ;
    
    return toOperatorTypeKey(
        operatorType.returnType()->key(),
        operatorType.operatorTypeId(),
        operatorType.ownerType() ? operatorType.ownerType()->key() : "",
        parameterTypeKeys
    );
}

}