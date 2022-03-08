#ifndef ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP
#define ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP

#include <string>
#include <memory>
#include <unordered_map>

#include "analyzer/Symbol.hpp"
#include "analyzer/FunctionSymbol.hpp"

#include "exceptions/SymbolNotFoundException.hpp"
#include "exceptions/DuplicateSymbolException.hpp"

namespace ice_script { namespace analyzer {

class SymbolTable
{
public:
    std::shared_ptr<Symbol> find(const std::string& name)
    {
        const auto it = symbolMap_.find(name);

        if (it != symbolMap_.end())
        {
            return it->second;
        }

        return nullptr;
    }

    std::shared_ptr<FunctionSymbol> findFunction(const std::string& name)
    {
        const auto it = symbolMap_.find(name);

        if (it != symbolMap_.end())
        {
            return it->second;
        }

        return nullptr;
    }

    std::shared_ptr<Symbol> get(const std::string& name)
    {
        auto symbol = find(name);

        if (!symbol) throw SymbolNotFoundException();

        return symbol;
    }

    const std::shared_ptr<Symbol>& get(const std::string& name) const
    {
//        const auto& symbol = find(name);
//
//        if (!symbol) throw SymbolNotFoundException();
//
//        return symbol;

        const auto it = symbolMap_.find(name);

        if (it == symbolMap_.end()) throw SymbolNotFoundException();

        return it->second;
    }

    std::shared_ptr<Symbol> create(const std::string& name)
    {
        const auto it = symbolMap_.find(name);

        if (it != symbolMap_.end())
        {
            throw DuplicateSymbolException();
        }

        symbolMap_[name] = std::make_shared<Symbol>(name);

        return symbolMap_[name];
    }

    void add(std::shared_ptr<Symbol> symbol)
    {
        const auto it = symbolMap_.find(symbol->name());

        if (it != symbolMap_.end()) throw DuplicateSymbolException();

        symbolMap_[symbol->name()] = std::move(symbol);
    }

    void add(std::shared_ptr<FunctionSymbol> symbol)
    {
        const auto it = functionSymbolMap_.find(symbol->name());

        if (it != functionSymbolMap_.end()) throw DuplicateSymbolException();

        functionSymbolMap_[symbol->name()] = std::move(symbol);
    }

private:
    std::unordered_map<std::string, std::shared_ptr<Symbol>> symbolMap_;
    std::unordered_map<std::string, std::shared_ptr<FunctionSymbol>> functionSymbolMap_;

};

}}

#endif //ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP
