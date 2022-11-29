#ifndef ICE_SCRIPT_ANALYZER_CONTEXT_HPP
#define ICE_SCRIPT_ANALYZER_CONTEXT_HPP

#include <string>
#include <memory>

#include "symbol/Symbol.hpp"
#include "symbol/SymbolTable.hpp"
#include "type/TypeTable.hpp"

#include "analyzer/detail/Scope.hpp"

#include "analyzer/detail/AnalyzerUtilities.hpp"

#include "logger/ILogger.hpp"

#include "exceptions/TypeNotFoundException.hpp"
#include "exceptions/DuplicateTypeException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

class Context
{
public:
    Context(logger::ILogger& logger) : logger_(&logger), rootScope_(std::make_unique<Scope>()), currentScope_(rootScope_.get())
    {
        expectedReturnTypes_.push_back(std::make_unique<std::vector<std::shared_ptr<Type>>>());
    }

    Context(logger::ILogger& logger, TypeTable& typeTable) : logger_(&logger), typeTable_(&typeTable), rootScope_(std::make_unique<Scope>()), currentScope_(rootScope_.get())
    {
        expectedReturnTypes_.push_back(std::make_unique<std::vector<std::shared_ptr<Type>>>());
    }

    logger::ILogger& logger() const
    {
        return *logger_;
    }

    Scope& scope()
    {
        return *currentScope_;
    }

    const Scope& scope() const
    {
        return *currentScope_;
    }

    TypeTable& typeTable()
    {
        return *typeTable_;
    }

    const TypeTable& typeTable() const
    {
        return *typeTable_;
    }

    void setTypeTable(TypeTable& typeTable)
    {
        typeTable_ = &typeTable;
    }

    SymbolTable& symbolTable()
    {
        return symbolTable_;
    }

    const SymbolTable& symbolTable() const
    {
        return symbolTable_;
    }

    void setSymbolTable(SymbolTable symbolTable)
    {
        symbolTable_ = std::move(symbolTable);
    }

    Scope& pushScope()
    {
        currentScope_ = &currentScope_->createChild();

        scopes_.push_back(currentScope_);

        return *currentScope_;
    }
    
    Scope& pushScope(std::string name, ScopeType scopeType)
    {
        currentScope_ = &currentScope_->createChild();

        currentScope_->setName(std::move(name));
        currentScope_->setType(scopeType);

        scopes_.push_back(currentScope_);

        return *currentScope_;
    }

    Scope& popScope()
    {
        currentScope_ = currentScope_->parent();

        return *currentScope_;
    }
    
    Scope* findScope(const ScopeType scopeType)
    {
        Scope* scope = currentScope_;
        
        while (scope)
        {
            if (scope->type() == scopeType) return scope;
            
            scope = scope->parent();
        }
        
        return nullptr;
    }
    
    void pushExpectedReturnTypes(std::vector<std::shared_ptr<Type>> expectedReturnTypes)
    {
        expectedReturnTypes_.push_back(std::make_unique<std::vector<std::shared_ptr<Type>>>(std::move(expectedReturnTypes)));
    }

    void popExpectedReturnTypes()
    {
        if (expectedReturnTypes_.size() == 1) throw RuntimeException("");

        expectedReturnTypes_.pop_back();
    }

    const std::vector<std::shared_ptr<Type>>& expectedReturnTypes() const
    {
        ICE_SCRIPT_ASSERT(!expectedReturnTypes_.empty());

        return *expectedReturnTypes_.back();
    }

protected:
    logger::ILogger* logger_;
    std::unique_ptr<Scope> rootScope_;
    std::vector<Scope*> scopes_;
    Scope* currentScope_ = nullptr;
    TypeTable* typeTable_;
    SymbolTable symbolTable_;
    std::vector<std::unique_ptr<std::vector<std::shared_ptr<Type>>>> expectedReturnTypes_{};
};

}}}

#endif //ICE_SCRIPT_ANALYZER_CONTEXT_HPP
