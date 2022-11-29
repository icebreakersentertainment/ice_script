#ifndef ICE_SCRIPT_GENERATOR_LLVMTYPETABLE_HPP
#define ICE_SCRIPT_GENERATOR_LLVMTYPETABLE_HPP

#include <memory>
#include <string>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>

#include "asg/Asg.hpp"

#include "type/ArrayType.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

class LlvmTypeTable
{
public:
//    friend std::ostream& operator<<(std::ostream& os, const LlvmTypeTable& llvmTypeTable);
//
//    friend std::string toString(const LlvmTypeTable& llvmTypeTable);

    ::llvm::Type* findByKey(const std::string& key)
    {
        const auto it = typeMap_.find(key);

        return (it != typeMap_.end() ? it->second : nullptr);
    }

    ::llvm::Type* findArrayByKey(const std::string& key)
    {
        const auto it = arrayTypeMap_.find(key);

        return (it != arrayTypeMap_.end() ? it->second : nullptr);
    }

    ::llvm::PointerType* findArrayValueTypeByKey(const std::string& key)
    {
        const auto it = arrayValueTypeMap_.find(key);

        return (it != arrayValueTypeMap_.end() ? it->second : nullptr);
    }

    ::llvm::StructType* findClassByKey(const std::string& key)
    {
        const auto it = classTypeMap_.find(key);

        return (it != classTypeMap_.end() ? it->second : nullptr);
    }

    ::llvm::FunctionType* findFunctionByKey(const std::string& key)
    {
        const auto it = functionTypeMap_.find(key);

        return (it != functionTypeMap_.end() ? it->second : nullptr);
    }

    ::llvm::PointerType* findPointerByKey(const std::string& key)
    {
        const auto it = classPointerTypeMap_.find(key);

        return (it != classPointerTypeMap_.end() ? it->second : nullptr);
    }

    ::llvm::Type& getByKey(const std::string& key)
    {
        const auto it = typeMap_.find(key);

        if (it == typeMap_.end()) throw TypeNotFoundException("");
        
        return *it->second;
    }

    ::llvm::Type& getArrayByKey(const std::string& key)
    {
        const auto it = arrayTypeMap_.find(key);

        if (it == arrayTypeMap_.end()) throw TypeNotFoundException("");
        
        return *it->second;
    }

    ::llvm::PointerType& getArrayValueTypeByKey(const std::string& key)
    {
        const auto it = arrayValueTypeMap_.find(key);

        if (it == arrayValueTypeMap_.end()) throw TypeNotFoundException("");
        
        return *it->second;
    }

    ::llvm::StructType& getClassByKey(const std::string& key)
    {
        const auto it = classTypeMap_.find(key);

        if (it == classTypeMap_.end()) throw TypeNotFoundException("");
        
        return *it->second;
    }

    ::llvm::FunctionType& getFunctionByKey(const std::string& key)
    {
        const auto it = functionTypeMap_.find(key);

        if (it == functionTypeMap_.end()) throw TypeNotFoundException("");
        
        return *it->second;
    }

    void add(const std::shared_ptr<Type>& type, ::llvm::Type* value)
    {
        if (typeMap_.find(type->key()) != typeMap_.end()) throw DuplicateTypeException();

        typeMap_[type->key()] = value;
    }

    // void add(const std::shared_ptr<ArrayType>& type, ::llvm::ArrayType* value)
    // {
    //     if (arrayTypeMap_.find(type->key()) != arrayTypeMap_.end()) throw DuplicateTypeException();
        
    //     add(std::static_pointer_cast<Type>(type), value);

    //     arrayTypeMap_[type->key()] = value;
    // }

    void add(const std::shared_ptr<ArrayType>& type, ::llvm::Type* value)
    {
        if (arrayTypeMap_.find(type->key()) != arrayTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        arrayTypeMap_[type->key()] = value;
    }
    
    void addValueType(const std::shared_ptr<ArrayType>& type, ::llvm::PointerType* value)
    {
        if (arrayValueTypeMap_.find(type->key()) != arrayValueTypeMap_.end()) throw DuplicateTypeException();
        
        add(type, value);

        arrayValueTypeMap_[type->key()] = value;
    }
    
    void addReferenceType(const std::shared_ptr<ArrayType>& type, ::llvm::PointerType* value)
    {
        if (arrayReferenceTypeMap_.find(type->key()) != arrayReferenceTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        arrayReferenceTypeMap_[type->key()] = value;
    }

    void addPointerType(const std::shared_ptr<ArrayType>& type, ::llvm::PointerType* value)
    {
        if (arrayPointerTypeMap_.find(type->key()) != arrayPointerTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        arrayPointerTypeMap_[type->key()] = value;
    }

    void add(const std::shared_ptr<ClassType>& type, ::llvm::StructType* value)
    {
        if (classTypeMap_.find(type->key()) != classTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        classTypeMap_[type->key()] = value;
    }

    void add(const std::shared_ptr<ClassType>& type, ::llvm::PointerType* value)
    {
        if (classPointerTypeMap_.find(type->key()) != classPointerTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        classPointerTypeMap_[type->key()] = value;
    }

    void add(const std::shared_ptr<FunctionType>& type, ::llvm::FunctionType* value)
    {
        if (functionTypeMap_.find(type->key()) != functionTypeMap_.end()) throw DuplicateTypeException();
        
        add(std::static_pointer_cast<Type>(type), value);

        functionTypeMap_[type->key()] = value;
    }
//    void add(std::shared_ptr<OperatorType> type);
//
//    const std::shared_ptr<UnknownType>& unknownType()
//    {
//        return unknownType_;
//    }

private:
    std::unordered_map<std::string, ::llvm::Type*> typeMap_;
    // std::unordered_map<std::string, ::llvm::ArrayType*> arrayTypeMap_;
    std::unordered_map<std::string, ::llvm::Type*> arrayTypeMap_;
    std::unordered_map<std::string, ::llvm::PointerType*> arrayValueTypeMap_;
    std::unordered_map<std::string, ::llvm::PointerType*> arrayReferenceTypeMap_;
    std::unordered_map<std::string, ::llvm::PointerType*> arrayPointerTypeMap_;
    std::unordered_map<std::string, ::llvm::StructType*> classTypeMap_;
    std::unordered_map<std::string, ::llvm::PointerType*> classPointerTypeMap_;
    std::unordered_map<std::string, ::llvm::FunctionType*> functionTypeMap_;
//    std::unordered_map<std::string, std::vector<std::shared_ptr<OperatorType>>> operatorTypeMap_;
//
//    std::shared_ptr<UnknownType> unknownType_ = std::make_shared<UnknownType>();
};

}}}}

#endif //ICE_SCRIPT_GENERATOR_LLVMTYPETABLE_HPP
