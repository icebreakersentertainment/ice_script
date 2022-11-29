#ifndef ICE_SCRIPT_TYPETABLEUTILITIES_HPP
#define ICE_SCRIPT_TYPETABLEUTILITIES_HPP

#include "type/TypeTable.hpp"

namespace ice_script { namespace analyzer {


// std::shared_ptr<ArrayType> createArrayType(const std::shared_ptr<Type>& type, std::vector<boost::optional<uint32_t>> dimensions = {boost::optional<uint32_t>{}});
// std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<Type>& type, const std::vector<boost::optional<uint32_t>>& dimensions = {boost::optional<uint32_t>{}});
// std::vector<std::shared_ptr<FunctionType>> createConstructorsForArrayType(const TypeTable& typeTable, std::shared_ptr<ArrayType>& arrayType);
// std::vector<std::shared_ptr<OperatorType>> createOperatorsForArrayType(
//     const std::vector<std::shared_ptr<ArrayType>>& arrayTypes,
//     const std::shared_ptr<Type>& indexValueType,
//     const std::shared_ptr<Type>& arrayElementReferenceType,
//     const std::shared_ptr<Type>& arrayElementConstReferenceType,
//     std::shared_ptr<ArrayType>& arrayType
// );

std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const TypeTable& typeTable, const std::shared_ptr<Type>& type, const std::vector<boost::optional<uint32_t>>& dimensions = {boost::optional<uint32_t>{}});

// std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<Type>& type, const std::vector<std::shared_ptr<Type>>& types);

// template <typename TypeType>
// std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<TypeType>& type, const std::vector<std::shared_ptr<TypeType>>& types)
// {
//     std::vector<std::shared_ptr<Type>> baseTypes{};
    
//     for (const auto& type : types) baseTypes.push_back(type);
    
//     return createArrayTypes(type, baseTypes);
// }

// template <>
// std::vector<std::shared_ptr<ArrayType>> createArrayTypes(const std::shared_ptr<Type>& type, const std::vector<std::shared_ptr<Type>>& types);

void populate(TypeTable& typeTable);

}}

#endif //ICE_SCRIPT_TYPETABLEUTILITIES_HPP
