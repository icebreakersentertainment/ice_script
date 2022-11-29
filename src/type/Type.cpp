#include "type/Type.hpp"

#include "type/OperatorType.hpp"
#include "type/ArrayType.hpp"
#include "type/OperatorTypes.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script
{

Type::Type(const TypeId typeId) : typeId_(typeId), operators_(std::make_unique<OperatorTypes>())
{
}

Type::Type(const Type& other)
{
    typeId_ = other.typeId_;
    name_ = other.name_;
    operators_ = std::make_unique<OperatorTypes>(*other.operators_);
    qualifiers_ = other.qualifiers_;
    modifier_ = other.modifier_;
}

Type::~Type()
{
    
}

Type& Type::operator=(const Type& other)
{
    typeId_ = other.typeId_;
    name_ = other.name_;
    operators_ = std::make_unique<OperatorTypes>(*other.operators_);
    qualifiers_ = other.qualifiers_;
    modifier_ = other.modifier_;
    
    return *this;
}

Type& Type::operator=(Type&& other)
{
    typeId_ = other.typeId_;
    name_ = std::move(other.name_);
    operators_ = std::move(other.operators_);
    qualifiers_ = other.qualifiers_;
    modifier_ = other.modifier_;
    
    return *this;
}

std::string toString(const Type& type)
{
    return "name: " + type.name()
        + ", typeId: " + toString(type.typeId())
        + ", modifier: " + toString(type.modifier())
        ;
}

std::ostream& operator<<(std::ostream& os, const Type& type)
{
    os << "(Type)[name: " + type.name() + ", typeId: " + toString(type.typeId()) << ", modifier: " + toString(type.modifier()) << "]";

    return os;
}

std::string toString(const Type::TypeId typeId)
{
    switch (typeId)
    {
        case Type::TypeId::UNKNOWN: return "UNKNOWN";
        case Type::TypeId::VOID_T: return "VOID_T";
        case Type::TypeId::BOOLEAN: return "BOOLEAN";
        case Type::TypeId::INTEGER8: return "INTEGER8";
        case Type::TypeId::INTEGER16: return "INTEGER16";
        case Type::TypeId::INTEGER32: return "INTEGER32";
        case Type::TypeId::INTEGER: return "INTEGER";
        case Type::TypeId::INTEGER64: return "INTEGER64";
        case Type::TypeId::UINTEGER8: return "UINTEGER8";
        case Type::TypeId::UINTEGER16: return "UINTEGER16";
        case Type::TypeId::UINTEGER32: return "UINTEGER32";
        case Type::TypeId::UINTEGER: return "UINTEGER";
        case Type::TypeId::UINTEGER64: return "UINTEGER64";
        case Type::TypeId::FLOAT: return "FLOAT";
        case Type::TypeId::DOUBLE: return "DOUBLE";
        case Type::TypeId::ARRAY: return "ARRAY";
        case Type::TypeId::CLASS: return "CLASS";
        case Type::TypeId::FUNCTION: return "FUNCTION";
        case Type::TypeId::OPERATOR: return "OPERATOR";

        default:
            throw InvalidArgumentException("Type id not valid.");
    }
}

std::ostream& operator<<(std::ostream& os, const Type::TypeId typeId)
{
    os << "(Type::TypeId)[" << toString(typeId) << "]";

    return os;
}

std::string toTypeKey(const Type& type)
{
    // std::vector<boost::optional<uint32_t>> dimensions{};
    // if (const auto arrayType = dynamic_cast<const ArrayType*>(&type); arrayType)
    // {
    //     dimensions = arrayType->dimensions();
    // }
    
    return toTypeKey(type.name(), type.qualifiers(), type.modifier());
}

// std::vector<std::shared_ptr<OperatorType>> Type::findOperators(const OperatorTypeId operatorTypeId)
// {
//     std::vector<std::shared_ptr<OperatorType>> operators{};
    
//     std::copy_if(operators_.begin(), operators_.end(), std::back_inserter(operators), [=](const auto& _operator) {
//         return _operator->operatorTypeId() == operatorTypeId;
//     });

//     return operators;
// }

// void Type::setOperators(std::vector<std::shared_ptr<OperatorType>> operators)
// {
//     operators_ = std::move(operators);
// }

}