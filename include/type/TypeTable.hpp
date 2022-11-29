#ifndef ICE_SCRIPT_ANALYZER_TYPETABLE_HPP
#define ICE_SCRIPT_ANALYZER_TYPETABLE_HPP

#include <string>
#include <memory>
#include <unordered_map>

#include "ast/PrimitiveType.hpp"

#include "type/Type.hpp"
#include "type/ArrayType.hpp"
#include "type/ClassType.hpp"
#include "type/FunctionType.hpp"
#include "type/OperatorType.hpp"
#include "type/PrimitiveType.hpp"
#include "type/TypeModifier.hpp"
#include "type/TypeQualifier.hpp"
#include "type/UnknownType.hpp"

#include "analyzer/detail/AnalyzerUtilities.hpp"

#include "detail/Assert.hpp"
#include "detail/InsertionOperators.hpp"
#include "detail/ToStringUtils.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

namespace ice_script
{

class TypeTable
{
public:
    friend std::ostream& operator<<(std::ostream& os, const TypeTable& typeTable);

    friend std::string toString(const TypeTable& typeTable);

    std::vector<std::shared_ptr<Type>> find(const std::string& name) const
    {
        const auto it = typeMap_.find(name);

        if (it != typeMap_.end()) return it->second;

        return {};
    }

    std::vector<std::shared_ptr<ArrayType>> findArray(const std::string& name) const
    {
        const auto it = arrayTypeMap_.find(name);

        if (it != arrayTypeMap_.end()) return it->second;

        return {};
    }

    std::vector<std::shared_ptr<ClassType>> findClass(const std::string& name) const
    {
        const auto it = classTypeMap_.find(name);

        if (it != classTypeMap_.end()) return it->second;

        return {};
    }

    std::vector<std::shared_ptr<FunctionType>> findFunction(const std::string& name) const
    {
        const auto it = functionTypeMap_.find(name);

        if (it != functionTypeMap_.end()) return it->second;

        return {};
    }

    std::vector<std::shared_ptr<OperatorType>> findOperators(const OperatorTypeId operatorTypeId) const
    {
        std::vector<std::shared_ptr<OperatorType>> operators{};

        for (const auto& it : operatorTypeMap_)
        {
            for (const auto& operatorType : it.second)
            {
                if (operatorType->operatorTypeId() == operatorTypeId) operators.push_back(operatorType);
            }
        }

        return operators;
    }

    std::shared_ptr<Type> findByKey(const std::string& key) const
    {
        const auto it = typeKeyMap_.find(key);

        if (it != typeKeyMap_.end()) return it->second;

        return {};
    }

    std::shared_ptr<ArrayType> findArrayByKey(const std::string& key) const
    {
        const auto it = arrayTypeKeyMap_.find(key);

        if (it != arrayTypeKeyMap_.end()) return it->second;

        return {};
    }

    std::shared_ptr<ClassType> findClassByKey(const std::string& key) const
    {
        const auto it = classTypeKeyMap_.find(key);

        if (it != classTypeKeyMap_.end()) return it->second;

        return {};
    }

    std::shared_ptr<FunctionType> findFunctionByKey(const std::string& key) const
    {
        const auto it = functionTypeKeyMap_.find(key);

        if (it != functionTypeKeyMap_.end()) return it->second;

        return {};
    }
    
    std::shared_ptr<Type> find(const std::shared_ptr<Type>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<Type>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return findByKey(needle->key());
    }

    std::shared_ptr<ArrayType> find(const std::shared_ptr<ArrayType>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<ArrayType>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return findArrayByKey(needle->key());
    }

    std::shared_ptr<ClassType> find(const std::shared_ptr<ClassType>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<ClassType>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return findClassByKey(needle->key());
    }
    
    std::vector<std::shared_ptr<Type>> findLike(const std::shared_ptr<Type>& type) const
    {
        std::vector<std::shared_ptr<Type>> results{};
        
        auto needle = std::make_shared<Type>(*type);
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::NONE);
        needle->setModifier(TypeModifier::VALUE);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::CONSTANT);
        needle->setModifier(TypeModifier::VALUE);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::NONE);
        needle->setModifier(TypeModifier::REFERENCE);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::CONSTANT);
        needle->setModifier(TypeModifier::REFERENCE);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::NONE);
        needle->setModifier(TypeModifier::POINTER);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::CONSTANT);
        needle->setModifier(TypeModifier::POINTER);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::NONE);
        needle->setModifier(TypeModifier::SMART_POINTER);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        needle->setQualifiers(TypeQualifier::TypeQualifierFlags::CONSTANT);
        needle->setModifier(TypeModifier::SMART_POINTER);
        
        if (auto result = findByKey(needle->key())) results.push_back(std::move(result));
        
        return results;
    }

    const std::vector<std::shared_ptr<Type>>& get(const std::string& name) const
    {
        const auto it = typeMap_.find(name);

        if (it == typeMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", name));

        return it->second;
    }

    const std::vector<std::shared_ptr<Type>>& get(const Type::TypeId typeId) const
    {
        const auto string = analyzer::detail::toName(typeId);

        const auto it = typeMap_.find(string);

        if (it == typeMap_.end()) throw TypeNotFoundException();

        return it->second;
    }

    const std::shared_ptr<Type>& get(const ast::PrimitiveType primitiveType) const
    {
        const auto string = analyzer::detail::toName(primitiveType);

        const auto it = typeMap_.find(string);

        if (it == typeMap_.end() || it->second.empty()) throw TypeNotFoundException();

        ICE_SCRIPT_ASSERT(it->second.size() == 1)

        return it->second[0];
    }

    const std::shared_ptr<ArrayType>& getArray(const std::string& name) const
    {
        const auto it = arrayTypeMap_.find(name);

        if (it == arrayTypeMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", name));

        return it->second[0];
    }

    const std::shared_ptr<ClassType>& getClass(const std::string& name) const
    {
        const auto it = classTypeMap_.find(name);

        if (it == classTypeMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", name));

        return it->second[0];
    }

    const std::shared_ptr<FunctionType>& getFunction(const std::string& name) const
    {
        const auto it = functionTypeMap_.find(name);

        if (it == functionTypeMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", name));

        return it->second[0];
    }

    const std::shared_ptr<Type>& getByKey(const std::string& key) const
    {
        const auto it = typeKeyMap_.find(key);

        if (it == typeKeyMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", key));

        return it->second;
    }

    const std::shared_ptr<ArrayType>& getArrayByKey(const std::string& key) const
    {
        const auto it = arrayTypeKeyMap_.find(key);

        if (it == arrayTypeKeyMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", key));

        return it->second;
    }

    const std::shared_ptr<ClassType>& getClassByKey(const std::string& key) const
    {
        const auto it = classTypeKeyMap_.find(key);

        if (it == classTypeKeyMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", key));

        return it->second;
    }

    const std::shared_ptr<FunctionType>& getFunctionByKey(const std::string& key) const
    {
        const auto it = functionTypeKeyMap_.find(key);

        if (it == functionTypeKeyMap_.end()) throw TypeNotFoundException(detail::format("Type '%s' not found.", key));

        return it->second;
    }
    // std::vector<std::shared_ptr<OperatorType>> findOperatorsByKey(const OperatorTypeId operatorTypeId);
    
    const std::shared_ptr<Type>& get(const std::shared_ptr<Type>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<Type>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return getByKey(needle->key());
    }

    const std::shared_ptr<ArrayType>& get(const std::shared_ptr<ArrayType>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<ArrayType>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return getArrayByKey(needle->key());
    }

    const std::shared_ptr<ClassType>& get(const std::shared_ptr<ClassType>& type, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        auto needle = std::make_shared<ClassType>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return getClassByKey(needle->key());
    }
    
    const std::shared_ptr<Type>& get(const ast::PrimitiveType primitiveType, const uint32_t qualifierFlags, const TypeModifier modifierFlag = TypeModifier::VALUE) const
    {
        const auto string = analyzer::detail::toName(primitiveType);

        const auto it = typeMap_.find(string);

        if (it == typeMap_.end() || it->second.empty()) throw TypeNotFoundException();

        // ICE_SCRIPT_ASSERT(it->second.size() == 1)

        const auto& type = it->second[0];
        
        auto needle = std::make_shared<Type>(*type);
        needle->setQualifiers(qualifierFlags);
        needle->setModifier(modifierFlag);
        
        return getByKey(needle->key());
    }
    
    void add(std::shared_ptr<Type> type)
    {
        auto& types = typeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(type);
        
        typeKeyMap_[type->key()] = type;
    }

    void add(std::shared_ptr<PrimitiveType> type)
    {
        add(std::static_pointer_cast<Type>(type));

        auto& types = primitiveTypeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(type);
        
        primitiveTypeKeyMap_[type->key()] = type;
    }

    void add(std::shared_ptr<ArrayType> type)
    {
        add(std::static_pointer_cast<Type>(type));

        auto& types = arrayTypeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(type);
        
        arrayTypeKeyMap_[type->key()] = type;
    }

    void add(std::shared_ptr<ClassType> type)
    {
        add(std::static_pointer_cast<Type>(type));

        auto& types = classTypeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(type);
        
        classTypeKeyMap_[type->key()] = type;
    }

    void add(std::shared_ptr<FunctionType> type)
    {
        add(std::static_pointer_cast<Type>(type));

        auto& types = functionTypeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(type);
        
        functionTypeKeyMap_[type->key()] = type;
    }

    void add(std::shared_ptr<OperatorType> type)
    {
        add(std::static_pointer_cast<Type>(type));

        auto& types = operatorTypeMap_[type->name()];

        const auto findIfIt = std::find_if(types.begin(), types.end(), [&](const auto& _type) { return _type == type; });

        if (findIfIt != types.end()) throw DuplicateTypeException();

        types.push_back(std::move(type));
    }

    const std::vector<std::shared_ptr<Type>> getAll() const
    {
        return {};
    }

    const std::vector<std::shared_ptr<PrimitiveType>> getAllPrimitives() const
    {
        std::vector<std::shared_ptr<PrimitiveType>> results{};

        for (const auto& kv : primitiveTypeMap_)
        {
            for (const auto& v : kv.second) results.push_back(v);
        }

        return results;
    }

    const std::vector<std::shared_ptr<ArrayType>> getAllArrays() const
    {
        std::vector<std::shared_ptr<ArrayType>> results{};

        for (const auto& kv : arrayTypeMap_)
        {
            for (const auto& v : kv.second) results.push_back(v);
        }

        return results;
    }

    const std::vector<std::shared_ptr<ClassType>> getAllClasses() const
    {
        std::vector<std::shared_ptr<ClassType>> results{};

        for (const auto& kv : classTypeMap_)
        {
            for (const auto& v : kv.second) results.push_back(v);
        }

        return results;
    }

    const std::vector<std::shared_ptr<FunctionType>> getAllFunctions() const
    {
        std::vector<std::shared_ptr<FunctionType>> results{};

        for (const auto& kv : functionTypeMap_)
        {
            for (const auto& v : kv.second) results.push_back(v);
        }

        return results;
    }

    const std::shared_ptr<UnknownType>& unknownType()
    {
        return unknownType_;
    }

private:
    std::unordered_map<std::string, std::vector<std::shared_ptr<Type>>> typeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<PrimitiveType>>> primitiveTypeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<ArrayType>>> arrayTypeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<ClassType>>> classTypeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<FunctionType>>> functionTypeMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<OperatorType>>> operatorTypeMap_;
    
    std::unordered_map<std::string, std::shared_ptr<Type>> typeKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<PrimitiveType>> primitiveTypeKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<ArrayType>> arrayTypeKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<ClassType>> classTypeKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<FunctionType>> functionTypeKeyMap_;
    // std::unordered_map<std::string, std::vector<std::shared_ptr<OperatorType>>> operatorTypeMap_;

    std::shared_ptr<UnknownType> unknownType_ = std::make_shared<UnknownType>();
};

}

#endif //ICE_SCRIPT_ANALYZER_TYPETABLE_HPP
