#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "type/FunctionType.hpp"

#include "detail/ToStringUtils.hpp"

namespace ice_script
{

FunctionType::FunctionType() : Type(Type::TypeId::FUNCTION), parameters_(std::make_unique<Types>())
{

}

FunctionType::FunctionType(const FunctionType& other) : Type(other)
{
    parameters_ = std::make_unique<Types>(*other.parameters_);
    returnType_ = other.returnType_;
    ownerType_ = other.ownerType_;
    isMethod_ = other.isMethod_;
    isConstructor_ = other.isConstructor_;
}

std::ostream& operator<<(std::ostream& os, const FunctionType& functionType)
{
    os << "(FunctionType)[name: " + functionType.name() + ", typeId: " + toString(functionType.typeId()) << "]";

    return os;
}

std::string toString(const FunctionType& functionType)
{
    return toString(static_cast<const Type&>(functionType))
        + ", ownerType: [" + (functionType.ownerType() ? toString(*functionType.ownerType()) : "null") + "]"
        + ", returnType: [" + toString(*functionType.returnType()) + "]"
        + ", parameters: {" + toString(functionType.parameters()) + "}"
        ;
}

std::string toFunctionTypeKey(const FunctionType& functionType)
{
    // static_assert(ranges::range<Types>, "It is not a range");
    // static_assert(ranges::range<Types&>, "It is not a range");
    // static_assert(ranges::range<detail::AbstractContainer<std::shared_ptr<Type>>>, "It is not a range");
    // static_assert(ranges::range<detail::AbstractContainer<std::shared_ptr<Type>>&>, "It is not a range");
    
    const auto parameterTypeKeys = functionType.parameters()
        | ranges::views::transform([&](const auto& parameterType) { return parameterType->key(); })
        | ranges::to<std::vector>()
        ;
    
    return toFunctionTypeKey(
        functionType.returnType()->key(),
        functionType.ownerType() ? functionType.ownerType()->key() : "",
        parameterTypeKeys
    );
}

}