#ifndef ICE_SCRIPT_TYPE_ARRAYTYPE_HPP
#define ICE_SCRIPT_TYPE_ARRAYTYPE_HPP

#include <utility>
#include <vector>
#include <memory>

// #include "type/Types.hpp"
#include "type/ConstructorTypes.hpp"
// #include "type/OperatorTypeId.hpp"

#include "detail/ToStringUtils.hpp"

namespace ice_script
{

inline std::string toArrayTypeKey(const uint32_t qualifiers, const std::string& elementTypeKey, const std::vector<boost::optional<uint32_t>>& dimensions, const TypeModifier modifier)
{
    std::string arrayAsString{};
    for (const auto& optionalDimensions : dimensions)
    {
        arrayAsString += "[" + (optionalDimensions ? std::to_string(optionalDimensions.get()) : "") + "]";
        // arrayAsString += "[]";
    }
    
    return ice_script::detail::format(
        "%s%s%s%s",
        (qualifiers & TypeQualifier::CONSTANT ? "c_" : ""),
        (modifier == TypeModifier::VALUE ? "v_" : (modifier == TypeModifier::REFERENCE ? "r_" : (modifier == TypeModifier::POINTER ? "p_" : ""))),
        elementTypeKey,
        arrayAsString
    );
}

class ArrayType;

std::string toArrayTypeKey(const ArrayType& arrayType);

class ArrayType : public Type
{
public:
    ArrayType() : Type(Type::TypeId::ARRAY)
    {

    }
    
    ArrayType(const ArrayType& other) : Type(other)
    {
        type_ = other.type_;
        constructors_ = other.constructors_;
        dimensions_ = other.dimensions_;
    }

    friend std::ostream& operator<<(std::ostream& os, const ArrayType& arrayType)
    {
        os << "(ArrayType)[name: " + arrayType.name() + ", typeId: " + toString(arrayType.typeId()) << "]";

        return os;
    }
    
    const std::string& key() const override
    {
        // if (!key_.empty()) return key_;
        
        key_ = toArrayTypeKey(*this);
        
        return key_;
    }

    std::shared_ptr<Type>& type()
    {
        return type_;
    }

    const std::shared_ptr<Type>& type() const
    {
        return type_;
    }
    
    void setType(std::shared_ptr<Type> type)
    {
        type_ = std::move(type);
    }

    ConstructorTypes& constructors()
    {
        return constructors_;
    }

    const ConstructorTypes& constructors() const
    {
        return constructors_;
    }
    
    void setDimensions(std::vector<boost::optional<uint32_t>> dimensions)
    {
        dimensions_ = std::move(dimensions);
    }
    
    const std::vector<boost::optional<uint32_t>>& dimensions() const
    {
        return dimensions_;
    }

protected:
    // std::vector<std::shared_ptr<Type>> memberVariables_;
    std::shared_ptr<Type> type_;
    // std::vector<std::shared_ptr<FunctionType>> constructors_;
    ConstructorTypes constructors_;
    std::vector<boost::optional<uint32_t>> dimensions_;

};

inline std::string toString(const ArrayType& arrayType)
{
    return toString(static_cast<const Type&>(arrayType))
        + ", type: [" + arrayType.type()->name() + "]"
        + ", constructors: [" + toString(arrayType.constructors()) + "]"
//        + ", returnType: [" + toString(*arrayType.returnType()) + "]"
//        + ", parameters: {" + toString(arrayType.parameters()) + "}"
        ;

}

}

#endif /* ICE_SCRIPT_TYPE_ARRAYTYPE_HPP */
