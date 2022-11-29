#ifndef ICE_SCRIPT_GENERATOR_LLVM_DETAIL_LLVMSYMBOLTABLE_HPP
#define ICE_SCRIPT_GENERATOR_LLVM_DETAIL_LLVMSYMBOLTABLE_HPP

#include <string>
#include <llvm/IR/Value.h>
#include <llvm/IR/DerivedTypes.h>

#include "asg/Asg.hpp"

#include "exceptions/SymbolNotFoundException.hpp"
#include "exceptions/DuplicateSymbolException.hpp"

namespace ice_script { namespace generator { namespace llvm { namespace detail {

class LlvmSymbolTable
{
public:
//    friend std::ostream& operator<<(std::ostream& os, const LlvmTypeTable& llvmTypeTable);
//
//    friend std::string toString(const LlvmTypeTable& llvmTypeTable);

    ::llvm::Value* findByKey(const std::string& key)
    {
        const auto it = symbolMap_.find(key);

        return (it != symbolMap_.end() ? it->second : nullptr);

    }

    // ::llvm::StructSymbol* findClassByKey(const std::string& key)
    // {
    //     const auto it = classSymbolMap_.find(key);

    //     return (it != classSymbolMap_.end() ? it->second : nullptr);
    // }

    ::llvm::Function* findFunctionByKey(const std::string& key)
    {
        const auto it = functionSymbolMap_.find(key);

        return (it != functionSymbolMap_.end() ? it->second : nullptr);
    }

    ::llvm::Value& getByKey(const std::string& key)
    {
        const auto it = symbolMap_.find(key);

        if (it == symbolMap_.end()) throw SymbolNotFoundException("");
        
        return *it->second;
    }

    // ::llvm::StructSymbol& getClassByKey(const std::string& key)
    // {
    //     const auto it = classSymbolMap_.find(key);

    //     if (it == classSymbolMap_.end()) throw SymbolNotFoundException("");
        
    //     return *it->second;
    // }

    ::llvm::Function& getFunctionByKey(const std::string& key)
    {
        const auto it = functionSymbolMap_.find(key);

        if (it == functionSymbolMap_.end()) throw SymbolNotFoundException("");
        
        return *it->second;
    }

    void add(const Symbol& symbol, ::llvm::Value* value)
    {
        if (symbolMap_.find(symbol.key()) != symbolMap_.end()) throw DuplicateSymbolException();

        symbolMap_[symbol.key()] = value;
    }

    // void add(const ClassSymbol& Symbol, ::llvm::StructSymbol* value)
    // {
    //     if (classSymbolMap_.find(Symbol.key()) != classSymbolMap_.end()) throw DuplicateSymbolException();

    //     classSymbolMap_[Symbol.key()] = value;
    // }

    void add(const FunctionSymbol& functionSymbol, ::llvm::Function* value)
    {
        if (functionSymbolMap_.find(functionSymbol.key()) != functionSymbolMap_.end()) throw DuplicateSymbolException();

        functionSymbolMap_[functionSymbol.key()] = value;
    }
//    void add(std::shared_ptr<OperatorType> type);
//
//    const std::shared_ptr<UnknownType>& unknownType()
//    {
//        return unknownType_;
//    }

private:
    std::unordered_map<std::string, ::llvm::Value*> symbolMap_;
    // std::unordered_map<std::string, ::llvm::StructType*> classTypeMap_;
    std::unordered_map<std::string, ::llvm::Function*> functionSymbolMap_;
//    std::unordered_map<std::string, std::vector<std::shared_ptr<OperatorType>>> operatorTypeMap_;
//
//    std::shared_ptr<UnknownType> unknownType_ = std::make_shared<UnknownType>();
};

}}}}

#endif /* ICE_SCRIPT_GENERATOR_LLVM_DETAIL_LLVMSYMBOLTABLE_HPP */
