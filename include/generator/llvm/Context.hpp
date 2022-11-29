#ifndef ICE_SCRIPT_GENERATOR_CONTEXT_HPP
#define ICE_SCRIPT_GENERATOR_CONTEXT_HPP

#include <memory>
#include <vector>

#include "generator/llvm/Scope.hpp"
#include "generator/llvm/detail/LlvmTypeTable.hpp"
#include "generator/llvm/detail/LlvmSymbolTable.hpp"

#include "type/TypeTable.hpp"
#include "symbol/SymbolTable.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace generator { namespace llvm {

class Context
{
public:
    Context(logger::ILogger& logger) : logger_(&logger), rootScope_(std::make_unique<Scope>()), currentScope_(rootScope_.get())
    {

    }

    logger::ILogger& logger()
    {
        return *logger_;
    }

    Scope& scope()
    {
        return *currentScope_;
    }

    const TypeTable& typeTable() const
    {
        return *typeTable_;
    }

    void setTypeTable(const TypeTable& typeTable)
    {
        typeTable_ = &typeTable;
    }

    const SymbolTable& symbolTable() const
    {
        return *symbolTable_;
    }

    void setSymbolTable(const SymbolTable& symbolTable)
    {
        symbolTable_ = &symbolTable;
    }

    detail::LlvmTypeTable& llvmTypeTable()
    {
        return llvmTypeTable_;
    }

    detail::LlvmSymbolTable& llvmSymbolTable()
    {
        return llvmSymbolTable_;
    }

    Scope& pushScope()
    {
        currentScope_ = &currentScope_->createChild();

        scopes_.push_back(currentScope_);

        return *currentScope_;
    }

    Scope& popScope()
    {
        currentScope_ = currentScope_->parent();

        return *currentScope_;
    }

private:
    logger::ILogger* logger_;
    std::unique_ptr<Scope> rootScope_;
    std::vector<Scope*> scopes_;
    Scope* currentScope_ = nullptr;
    const TypeTable* typeTable_;
    const SymbolTable* symbolTable_;
    detail::LlvmTypeTable llvmTypeTable_;
    detail::LlvmSymbolTable llvmSymbolTable_;
};

}}}

#endif //ICE_SCRIPT_GENERATOR_CONTEXT_HPP
