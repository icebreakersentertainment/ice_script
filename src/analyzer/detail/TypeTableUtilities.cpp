#include <memory>

#include "analyzer/detail/TypeTableUtilities.hpp"

#include "ast/PrimitiveType.hpp"

#include "type/OperatorType.hpp"
#include "type/ArrayType.hpp"
#include "type/PrimitiveType.hpp"
#include "type/TypeModifier.hpp"
#include "type/TypeQualifier.hpp"

#include "detail/Format.hpp"

namespace ice_script { namespace analyzer {

using namespace ranges;
using namespace ranges::views;

using namespace ice_script::ast;
using namespace ice_script::asg;

using PrimitiveTypeMap = std::unordered_map<ast::PrimitiveType, std::vector<std::shared_ptr<ice_script::PrimitiveType>>>;

std::vector<std::shared_ptr<FunctionType>> createConstructorsForArrayType(const TypeTable& typeTable, const std::shared_ptr<ArrayType>& arrayType)
{
    std::vector<std::shared_ptr<FunctionType>> constructors{};
    
    auto defaultConstructor = std::make_shared<FunctionType>();
    defaultConstructor->setName(arrayType->name());
    defaultConstructor->setReturnType(arrayType);
    defaultConstructor->setOwnerType(arrayType);
    defaultConstructor->setIsMethod(true);
    defaultConstructor->setIsConstructor(true);
    
    constructors.push_back(defaultConstructor);

    return constructors;
}

std::vector<std::shared_ptr<OperatorType>> createIndexOperators(
    const TypeTable& typeTable,
    const std::shared_ptr<Type>& indexValueType,
    const std::shared_ptr<Type>& indexOperatorReturnType,
    const std::shared_ptr<Type>& indexOperatorReturnConstType,
    const std::shared_ptr<Type>& type
)
{
    std::vector<std::shared_ptr<OperatorType>> operators{};
    
    if (!(type->qualifiers() & TypeQualifier::TypeQualifierFlags::CONSTANT))
    {
        auto indexOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::INDEX);
        indexOperator->setOwnerType(type);
        indexOperator->setReturnType(indexOperatorReturnType);
        indexOperator->parameters().add(indexValueType);
        
        operators.push_back(indexOperator);
    }
    
    auto constIndexOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::INDEX);
    constIndexOperator->setQualifiers(TypeQualifier::TypeQualifierFlags::CONSTANT);
    constIndexOperator->setOwnerType(type);
    constIndexOperator->setReturnType(indexOperatorReturnConstType);
    constIndexOperator->parameters().add(indexValueType);
    
    operators.push_back(constIndexOperator);
    
    return operators;
}

std::vector<std::shared_ptr<OperatorType>> createIndexOperators(const TypeTable& typeTable, const std::shared_ptr<ArrayType>& arrayType)
{
    const auto& indexValueType = typeTable.get(ast::PrimitiveType::UINT64, TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::VALUE);
    const auto& indexOperatorReturnType = typeTable.get(arrayType->type(), TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::REFERENCE);
    const auto& indexOperatorReturnConstType = typeTable.get(arrayType->type(), TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::REFERENCE);
    
    return createIndexOperators(typeTable, indexValueType, indexOperatorReturnType, indexOperatorReturnConstType, arrayType);
}

template <typename T>
std::vector<std::shared_ptr<OperatorType>> createImplicitConversionOperators(const TypeTable& typeTable, const std::vector<std::shared_ptr<T>>& types, const std::shared_ptr<T>& type)
{
    std::vector<std::shared_ptr<OperatorType>> implicitConversionOperators{};

    for (const auto& _type : types)
    {
        if (type == _type) continue;

        auto implicitConversionOperator = std::make_shared<OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
        implicitConversionOperator->setOwnerType(type);
        implicitConversionOperator->setReturnType(_type);

        implicitConversionOperators.push_back(implicitConversionOperator);
    }
    
    return implicitConversionOperators;
}

std::vector<std::shared_ptr<OperatorType>> createAssignEqualOperators(const TypeTable& typeTable, const std::shared_ptr<Type>& type)
{
    auto assignEqualOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::ASSIGN_EQUAL);
    assignEqualOperator->setOwnerType(type);
    assignEqualOperator->setReturnType(type);
    assignEqualOperator->parameters().add(type);
    
    return {assignEqualOperator};
}

std::vector<std::shared_ptr<OperatorType>> createOperatorsForArrayType(const TypeTable& typeTable, const std::vector<std::shared_ptr<ArrayType>>& arrayTypes, const std::shared_ptr<ArrayType>& arrayType)
{
    const auto implicitConversionOperators = createImplicitConversionOperators(typeTable, arrayTypes, arrayType);
    const auto assignEqualOperators        = createAssignEqualOperators(typeTable, arrayType);
    const auto indexOperators              = createIndexOperators(typeTable, arrayType);
    
    return concat(implicitConversionOperators, assignEqualOperators, indexOperators) | to<std::vector>();
}

auto createOperatorsForPrimitiveType(PrimitiveTypeMap& primitiveTypesMap, std::shared_ptr<ice_script::PrimitiveType>& primitiveType)
{
    std::vector<std::shared_ptr<ice_script::OperatorType>> operators{};

    if (primitiveType->typeId() == Type::TypeId::VOID_T)
    {
        return operators;
    }

    for (const auto& kv: primitiveTypesMap)
    {
        for (const auto& _primitiveType : kv.second)
        {
            if (primitiveType == _primitiveType) continue;

            auto implicitConversionOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::IMPLICIT_CONVERSION);
            implicitConversionOperator->setOwnerType(primitiveType);
            implicitConversionOperator->setReturnType(_primitiveType);

            operators.push_back(implicitConversionOperator);
        }
    }

//    for (const auto& kv: primitiveTypesMap)
//    {
//        auto addOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::ADD);
//        addOperator->setOwnerType(primitiveType);
//        addOperator->setReturnType(kv.second);
//        addOperator->setParameters({kv.second});
//
//        operators.push_back(addOperator);
//    }

    auto addOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::ADD);
    addOperator->setOwnerType(primitiveType);
    addOperator->setReturnType(primitiveType);
    addOperator->parameters().add(primitiveType);

    operators.push_back(addOperator);

    auto subtractOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::SUBTRACT);
    subtractOperator->setOwnerType(primitiveType);
    subtractOperator->setReturnType(primitiveType);
    subtractOperator->parameters().add(primitiveType);

    operators.push_back(subtractOperator);

//    for (const auto& kv: primitiveTypesMap)
//    {
//        auto addOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::EQUALS);
//        addOperator->setOwnerType(primitiveType);
//        addOperator->setReturnType(primitiveTypesMap[ast::PrimitiveType::BOOLEAN]);
//        addOperator->setParameters({kv.second});
//
//        operators.push_back(addOperator);
//    }

    auto equalsOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::EQUALS);
    equalsOperator->setOwnerType(primitiveType);
    equalsOperator->setReturnType(primitiveTypesMap[ast::PrimitiveType::BOOLEAN].at(0));
    equalsOperator->parameters().add(primitiveType);

    operators.push_back(equalsOperator);

    auto lessThanOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::LESS_THAN);
    lessThanOperator->setOwnerType(primitiveType);
    lessThanOperator->setReturnType(primitiveTypesMap[ast::PrimitiveType::BOOLEAN].at(0));
    lessThanOperator->parameters().add(primitiveType);

    operators.push_back(lessThanOperator);

    auto assignEqualOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::ASSIGN_EQUAL);
    assignEqualOperator->setOwnerType(primitiveType);
    assignEqualOperator->setReturnType(primitiveType);
    assignEqualOperator->parameters().add(primitiveType);

    operators.push_back(assignEqualOperator);

    if (primitiveType->typeId() == Type::TypeId::BOOLEAN)
    {
        auto andOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::AND);
        andOperator->setOwnerType(primitiveType);
        andOperator->setReturnType(primitiveType);
        andOperator->parameters().add(primitiveType);

        operators.push_back(andOperator);

        auto orOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::OR);
        orOperator->setOwnerType(primitiveType);
        orOperator->setReturnType(primitiveType);
        orOperator->parameters().add(primitiveType);

        operators.push_back(orOperator);
    }

    auto postfixIncrementOperator = std::make_shared<ice_script::OperatorType>(OperatorTypeId::POSTFIX_INCREMENT);
    postfixIncrementOperator->setOwnerType(primitiveType);
    postfixIncrementOperator->setReturnType(primitiveType);

    operators.push_back(postfixIncrementOperator);

    return operators;
}

std::vector<std::shared_ptr<ice_script::PrimitiveType>> createPrimitiveTypes(const ast::PrimitiveType primitiveType, std::string name)
{
    auto type = std::make_shared<ice_script::PrimitiveType>(primitiveType);
    type->setName(std::move(name));
    
    auto constType = std::make_shared<ice_script::PrimitiveType>(*type);
    constType->setQualifiers(TypeQualifier::CONSTANT);
    
    auto referenceType = std::make_shared<ice_script::PrimitiveType>(*type);
    referenceType->setModifier(TypeModifier::REFERENCE);
    
    auto constReferenceType = std::make_shared<ice_script::PrimitiveType>(*constType);
    constReferenceType->setModifier(TypeModifier::REFERENCE);
    
    auto pointerType = std::make_shared<ice_script::PrimitiveType>(*type);
    pointerType->setModifier(TypeModifier::POINTER);
    
    auto constPointerType = std::make_shared<ice_script::PrimitiveType>(*constType);
    constPointerType->setModifier(TypeModifier::POINTER);
    
    return {type, constType, referenceType, constReferenceType, pointerType, constPointerType};
}

// std::shared_ptr<ArrayType> createArrayType(const std::shared_ptr<Type>& type, std::vector<boost::optional<uint32_t>> dimensions)
// {
//     auto arrayType = std::make_shared<ArrayType>();
    
//     arrayType->setName(ice_script::detail::format("%s[%s]", type->name(), (!dimensions.empty() && dimensions[0] ? std::to_string(dimensions[0].get()) : "")));
//     arrayType->setType(type);
//     arrayType->setDimensions(std::move(dimensions));
    
//     return arrayType;
// }

std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<Type>& type, const std::vector<boost::optional<uint32_t>>& dimensions)
{
    auto arrayType = std::make_shared<ArrayType>();
    
    arrayType->setName(ice_script::detail::format("%s[%s]", type->name(), (!dimensions.empty() && dimensions[0] ? std::to_string(dimensions[0].get()) : "")));
    arrayType->setType(type);
    arrayType->setDimensions(std::move(dimensions));
    
    auto constArrayType = std::make_shared<ice_script::ArrayType>(*arrayType);
    constArrayType->setQualifiers(TypeQualifier::CONSTANT);
    
    auto referenceArrayType = std::make_shared<ice_script::ArrayType>(*arrayType);
    referenceArrayType->setModifier(TypeModifier::REFERENCE);
    
    auto constReferenceArrayType = std::make_shared<ice_script::ArrayType>(*constArrayType);
    constReferenceArrayType->setModifier(TypeModifier::REFERENCE);
    
    auto pointerArrayType = std::make_shared<ice_script::ArrayType>(*arrayType);
    pointerArrayType->setModifier(TypeModifier::POINTER);
    
    auto constPointerArrayType = std::make_shared<ice_script::ArrayType>(*constArrayType);
    constPointerArrayType->setModifier(TypeModifier::POINTER);
    
    return {arrayType, constArrayType, referenceArrayType, constReferenceArrayType, pointerArrayType, constPointerArrayType};
}

std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const TypeTable& typeTable, const std::shared_ptr<Type>& type, const std::vector<boost::optional<uint32_t>>& dimensions)
{
    // const auto& valueType          = typeTable.get(type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::VALUE);
    // const auto& constValueType     = typeTable.get(type, TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::VALUE);
    // const auto& referenceType      = typeTable.get(type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::REFERENCE);
    // const auto& constReferenceType = typeTable.get(type, TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::REFERENCE);
    // const auto& pointerType        = typeTable.get(type, TypeQualifier::TypeQualifierFlags::NONE, TypeModifier::POINTER);
    // const auto& constPointerType   = typeTable.get(type, TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::POINTER);
    
    // const auto valueArrayTypes          = createArrayTypes(valueType, dimensions);
    // const auto constValueArrayTypes     = createArrayTypes(constValueType, dimensions);
    // const auto referenceArrayTypes      = createArrayTypes(referenceType, dimensions);
    // const auto constReferenceArrayTypes = createArrayTypes(constReferenceType, dimensions);
    // const auto pointerArrayTypes        = createArrayTypes(pointerType, dimensions);
    // const auto constPointerArrayTypes   = createArrayTypes(constPointerType, dimensions);
    
    // auto arrayTypes = concat(valueArrayTypes, constValueArrayTypes, referenceArrayTypes, constReferenceArrayTypes, pointerArrayTypes, constPointerArrayTypes);
    
    auto arrayTypes = createArrayTypes(type, dimensions);
    
    for (const auto& arrayType : arrayTypes) arrayType->constructors().add(createConstructorsForArrayType(typeTable, arrayType));
    for (const auto& arrayType : arrayTypes) arrayType->operators().add(createOperatorsForArrayType(typeTable, arrayTypes, arrayType));
    
    // for (auto& arrayType : arrayTypes)
    // {
        
    //     // arrayType->operators().add(createOperatorsForArrayType(typeTable, {valueType, constValueType, referenceType, constReferenceType, pointerType, constPointerType}, arrayType));
    // }
    
    return arrayTypes;
}

// template <typename TypeType>
// std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<Type>& type, const std::vector<std::shared_ptr<Type>>& types)
// {
//     const auto constTypeIt = std::find_if(types.begin(), types.end(), [&](const auto& type) {
//         return type->modifier() == TypeModifier::VALUE && type->qualifiers() == TypeQualifier::TypeQualifierFlags::CONSTANT;
//     });
//     const auto referenceTypeIt = std::find_if(types.begin(), types.end(), [&](const auto& type) {
//         return type->modifier() == TypeModifier::REFERENCE && type->qualifiers() != TypeQualifier::TypeQualifierFlags::CONSTANT;
//     });
//     const auto constReferenceTypeIt = std::find_if(types.begin(), types.end(), [&](const auto& type) {
//         return type->modifier() == TypeModifier::REFERENCE && type->qualifiers() == TypeQualifier::TypeQualifierFlags::CONSTANT;
//     });
//     const auto pointerTypeIt = std::find_if(types.begin(), types.end(), [&](const auto& type) {
//         return type->modifier() == TypeModifier::POINTER && type->qualifiers() != TypeQualifier::TypeQualifierFlags::CONSTANT;
//     });
//     const auto constPointerTypeIt = std::find_if(types.begin(), types.end(), [&](const auto& type) {
//         return type->modifier() == TypeModifier::POINTER && type->qualifiers() == TypeQualifier::TypeQualifierFlags::CONSTANT;
//     });
    
//     const std::shared_ptr<Type> constType =  (constTypeIt != types.end() ? *constTypeIt : nullptr);
//     const std::shared_ptr<Type> referenceType =  (referenceTypeIt != types.end() ? *referenceTypeIt : nullptr);
//     const std::shared_ptr<Type> constReferenceType =  (constReferenceTypeIt != types.end() ? *constReferenceTypeIt : nullptr);
//     const std::shared_ptr<Type> pointerType =  (pointerTypeIt != types.end() ? *pointerTypeIt : nullptr);
//     const std::shared_ptr<Type> constPointerType =  (constPointerTypeIt != types.end() ? *constPointerTypeIt : nullptr);
    
//     const auto arrayTypes = createArrayTypes(type);
//     const auto constArrayTypes = createArrayTypes(constType);
//     const auto referenceArrayTypes = createArrayTypes(referenceType);
//     const auto constReferenceArrayTypes = createArrayTypes(constReferenceType);
//     const auto pointerArrayTypes = createArrayTypes(pointerType);
//     const auto constPointerArrayTypes = createArrayTypes(constPointerType);
    
//     std::vector<std::shared_ptr<ArrayType>> results{};
    
//     results.reserve(arrayTypes.size() + constArrayTypes.size() + referenceArrayTypes.size() + constReferenceArrayTypes.size() + pointerArrayTypes.size() + constPointerArrayTypes.size());
    
//     std::copy(arrayTypes.begin(), arrayTypes.end(), std::back_inserter(results));
//     std::copy(constArrayTypes.begin(), constArrayTypes.end(), std::back_inserter(results));
//     std::copy(referenceArrayTypes.begin(), referenceArrayTypes.end(), std::back_inserter(results));
//     std::copy(constReferenceArrayTypes.begin(), constReferenceArrayTypes.end(), std::back_inserter(results));
//     std::copy(pointerArrayTypes.begin(), pointerArrayTypes.end(), std::back_inserter(results));
//     std::copy(constPointerArrayTypes.begin(), constPointerArrayTypes.end(), std::back_inserter(results));
    
//     return results;
    
//     // auto arrayType = std::make_shared<ArrayType>();
//     // arrayType->setName(ice_script::detail::format("%s[]", type->name()));
//     // arrayType->setType(type);
//     // arrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     // auto constArrayType = std::make_shared<ArrayType>(*arrayType);
//     // constArrayType->setQualifiers(TypeQualifier::CONSTANT);
//     // constArrayType->setType(constType);
//     // constArrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     // auto referenceArrayType = std::make_shared<ArrayType>(*arrayType);
//     // referenceArrayType->setModifier(TypeModifier::REFERENCE);
//     // referenceArrayType->setType(referenceType);
//     // referenceArrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     // auto constReferenceArrayType = std::make_shared<ArrayType>(*constArrayType);
//     // constReferenceArrayType->setModifier(TypeModifier::REFERENCE);
//     // constReferenceArrayType->setType(constReferenceType);
//     // constReferenceArrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     // auto pointerArrayType = std::make_shared<ArrayType>(*arrayType);
//     // pointerArrayType->setModifier(TypeModifier::POINTER);
//     // pointerArrayType->setType(pointerType);
//     // pointerArrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     // auto constPointerArrayType = std::make_shared<ArrayType>(*constArrayType);
//     // constPointerArrayType->setModifier(TypeModifier::POINTER);
//     // constPointerArrayType->setType(constPointerType);
//     // constPointerArrayType->setDimensions({boost::optional<uint32_t>{}});
    
//     const auto arrayTypes = createArrayTypes(type);
//     const auto constArrayTypes = createArrayTypes(constType);
//     const auto referenceArrayTypes = createArrayTypes(referenceType);
//     const auto constReferenceArrayTypes = createArrayTypes(constReferenceType);
//     const auto pointerArrayTypes = createArrayTypes(pointerType);
//     const auto constPointerArrayTypes = createArrayTypes(constPointerType);
    
//     std::vector<std::shared_ptr<ArrayType>> results{};
    
//     results.reserve(arrayTypes.size() + constArrayTypes.size() + referenceArrayTypes.size() + constReferenceArrayTypes.size() + pointerArrayTypes.size() + constPointerArrayTypes.size());
    
//     std::copy(arrayTypes.begin(), arrayTypes.end(), std::back_inserter(results));
//     std::copy(constArrayTypes.begin(), constArrayTypes.end(), std::back_inserter(results));
//     std::copy(referenceArrayTypes.begin(), referenceArrayTypes.end(), std::back_inserter(results));
//     std::copy(constReferenceArrayTypes.begin(), constReferenceArrayTypes.end(), std::back_inserter(results));
//     std::copy(pointerArrayTypes.begin(), pointerArrayTypes.end(), std::back_inserter(results));
//     std::copy(constPointerArrayTypes.begin(), constPointerArrayTypes.end(), std::back_inserter(results));
    
//     return results;
// }

void populate(TypeTable& typeTable)
{
    PrimitiveTypeMap primitiveTypesMap{};
    
    primitiveTypesMap[ast::PrimitiveType::VOID_T]  = createPrimitiveTypes(ast::PrimitiveType::VOID_T, "void");
    primitiveTypesMap[ast::PrimitiveType::BOOLEAN] = createPrimitiveTypes(ast::PrimitiveType::BOOLEAN, "bool");
    primitiveTypesMap[ast::PrimitiveType::INT8]    = createPrimitiveTypes(ast::PrimitiveType::INT8, "int8");
    primitiveTypesMap[ast::PrimitiveType::INT16]   = createPrimitiveTypes(ast::PrimitiveType::INT16, "int16");
    primitiveTypesMap[ast::PrimitiveType::INT32]   = createPrimitiveTypes(ast::PrimitiveType::INT32, "int32");
    primitiveTypesMap[ast::PrimitiveType::INT]     = createPrimitiveTypes(ast::PrimitiveType::INT, "int");
    primitiveTypesMap[ast::PrimitiveType::INT64]   = createPrimitiveTypes(ast::PrimitiveType::INT64, "int64");
    primitiveTypesMap[ast::PrimitiveType::UINT8]   = createPrimitiveTypes(ast::PrimitiveType::UINT8, "uint8");
    primitiveTypesMap[ast::PrimitiveType::UINT16]  = createPrimitiveTypes(ast::PrimitiveType::UINT16, "uint16");
    primitiveTypesMap[ast::PrimitiveType::UINT32]  = createPrimitiveTypes(ast::PrimitiveType::UINT32, "uint32");
    primitiveTypesMap[ast::PrimitiveType::UINT]    = createPrimitiveTypes(ast::PrimitiveType::UINT, "uint");
    primitiveTypesMap[ast::PrimitiveType::UINT64]  = createPrimitiveTypes(ast::PrimitiveType::UINT64, "uint64");
    primitiveTypesMap[ast::PrimitiveType::FLOAT]   = createPrimitiveTypes(ast::PrimitiveType::FLOAT, "float");
    primitiveTypesMap[ast::PrimitiveType::DOUBLE]  = createPrimitiveTypes(ast::PrimitiveType::DOUBLE, "double");
    
    for (auto& kv : primitiveTypesMap)
    {
        for (auto& primitiveType : kv.second)
        {
            auto operators = createOperatorsForPrimitiveType(primitiveTypesMap, primitiveType);
            primitiveType->operators().add(operators);
        }
    }
    
    for (auto& kv : primitiveTypesMap)
    {
        for (auto& primitiveType : kv.second) typeTable.add(primitiveType);
    }
    
    for (auto& kv : primitiveTypesMap)
    {
        if (kv.first == ast::PrimitiveType::VOID_T) continue;
        
        for (const auto& type : kv.second)
        {
            const auto arrayTypes = createArrayTypes(typeTable, type);
            
            for (const auto& arrayType : arrayTypes) typeTable.add(arrayType);
        }
    }
}

}}