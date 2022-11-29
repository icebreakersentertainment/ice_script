#ifndef ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP
#define ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP

#include <string>
#include <memory>
#include <unordered_map>

#include "symbol/Symbol.hpp"
#include "symbol/FunctionSymbol.hpp"
#include "symbol/ArraySymbol.hpp"
#include "symbol/ClassSymbol.hpp"

#include "exceptions/SymbolNotFoundException.hpp"
#include "exceptions/DuplicateSymbolException.hpp"

#include "detail/InsertionOperators.hpp"
#include "detail/ToStringUtils.hpp"

namespace ice_script
{

class SymbolTable
{
public:
    SymbolTable(SymbolTable* parent = nullptr) : parent_(parent)
    {}

    friend std::ostream& operator<<(std::ostream& os, const SymbolTable& symbolTable)
    {
        os << "(" << boost::typeindex::type_id<SymbolTable>().pretty_name() << ")["
        << "symbolMap: " << symbolTable.symbolMap_
        << ", functionSymbolMap: " << symbolTable.functionSymbolMap_
        << ", classSymbolMap: " << symbolTable.classSymbolMap_
        << "]";

        return os;
    }

    friend std::string toString(const SymbolTable& symbolTable)
    {
        using namespace std::string_literals;

        return "(SymbolTable)[\n"s
            + "\tsymbolMap: "s + detail::toString(symbolTable.symbolMap_)
            + ",\n\tfunctionSymbolMap: " + detail::toString(symbolTable.functionSymbolMap_)
            + ",\n\tclassSymbolMap: " + detail::toString(symbolTable.classSymbolMap_)
            + "\n]";
    }

    std::vector<std::shared_ptr<Symbol>> find(const std::string& name) const
    {
        const auto it = symbolMap_.find(name);

        if (it != symbolMap_.end()) return it->second;

        return parent_ ? parent_->find(name) : std::vector<std::shared_ptr<Symbol>>();
    }

    std::vector<std::shared_ptr<FunctionSymbol>> findFunction(const std::string& name) const
    {
        const auto it = functionSymbolMap_.find(name);

        if (it != functionSymbolMap_.end()) return it->second;

        return parent_ ? parent_->findFunction(name) : std::vector<std::shared_ptr<FunctionSymbol>>();
    }

    std::vector<std::shared_ptr<ArraySymbol>> findArray(const std::string& name) const
    {
        const auto it = arraySymbolMap_.find(name);

        if (it != arraySymbolMap_.end()) return it->second;
        
        return parent_ ? parent_->findArray(name) : std::vector<std::shared_ptr<ArraySymbol>>();
    }
    
    std::vector<std::shared_ptr<ClassSymbol>> findClass(const std::string& name) const
    {
        const auto it = classSymbolMap_.find(name);

        if (it != classSymbolMap_.end()) return it->second;
        
        return parent_ ? parent_->findClass(name) : std::vector<std::shared_ptr<ClassSymbol>>();
    }
    
    std::shared_ptr<Symbol> findByKey(const std::string& key) const
    {
        const auto it = symbolKeyMap_.find(key);

        if (it != symbolKeyMap_.end()) return it->second;

        return parent_ ? parent_->findByKey(key) : nullptr;
    }

    std::shared_ptr<FunctionSymbol> findFunctionByKey(const std::string& key) const
    {
        const auto it = functionSymbolKeyMap_.find(key);

        if (it != functionSymbolKeyMap_.end()) return it->second;

        return parent_ ? parent_->findFunctionByKey(key) : nullptr;
    }

    std::shared_ptr<ClassSymbol> findClassByKey(const std::string& key) const
    {
        const auto it = classSymbolKeyMap_.find(key);

        if (it != classSymbolKeyMap_.end()) return it->second;

        return parent_ ? parent_->findClassByKey(key) : nullptr;
    }

    const std::shared_ptr<Symbol>& getByKey(const std::string& key) const
    {
        const auto it = symbolKeyMap_.find(key);

        if (it != symbolKeyMap_.end()) return it->second;

        if (!parent_) throw SymbolNotFoundException(detail::format("Symbol with key '%s' not found.", key));

        return static_cast<const SymbolTable*>(parent_)->getByKey(key);
    }

    const std::shared_ptr<FunctionSymbol>& getFunctionByKey(const std::string& key) const
    {
        const auto it = functionSymbolKeyMap_.find(key);

        if (it != functionSymbolKeyMap_.end()) return it->second;

        if (parent_) return parent_->getFunctionByKey(key);

        throw SymbolNotFoundException(detail::format("Function symbol with key '%s' not found.", key));
    }
    
    const std::shared_ptr<ArraySymbol>& getArrayByKey(const std::string& key) const
    {
        const auto it = arraySymbolKeyMap_.find(key);

        if (it != arraySymbolKeyMap_.end()) return it->second;

        if (parent_) return parent_->getArrayByKey(key);

        throw SymbolNotFoundException(detail::format("Array symbol with key '%s' not found.", key));
    }
    
    const std::shared_ptr<ClassSymbol>& getClassByKey(const std::string& key) const
    {
        const auto it = classSymbolKeyMap_.find(key);

        if (it != classSymbolKeyMap_.end()) return it->second;

        if (parent_) return parent_->getClassByKey(key);

        throw SymbolNotFoundException(detail::format("Class symbol with key '%s' not found.", key));
    }
    
    std::vector<std::shared_ptr<Symbol>> getAll() const
    {
        std::vector<std::shared_ptr<Symbol>> results{};

        for (const auto& kv : symbolKeyMap_)
        {
            results.push_back(kv.second);
        }

        return results; 
    }
    
    std::vector<std::shared_ptr<FunctionSymbol>> getAllFunctions() const
    {
        std::vector<std::shared_ptr<FunctionSymbol>> results{};

        for (const auto& kv : functionSymbolMap_)
        {
            for (const auto& symbol : kv.second) results.push_back(symbol);
        }

        return results; 
    }
    
    std::vector<std::shared_ptr<ArraySymbol>> getAllArrays() const
    {
        std::vector<std::shared_ptr<ArraySymbol>> results{};

        for (const auto& kv : arraySymbolMap_)
        {
            for (const auto& symbol : kv.second) results.push_back(symbol);
        }

        return results; 
    }

    std::vector<std::shared_ptr<ClassSymbol>> getAllClasses() const
    {
        std::vector<std::shared_ptr<ClassSymbol>> results{};

        for (const auto& kv : classSymbolMap_)
        {
            for (const auto& symbol : kv.second) results.push_back(symbol);
        }

        return results; 
    }

    void add(std::shared_ptr<Symbol> symbol)
    {
        auto& symbols = symbolMap_[symbol->name()];

        const auto findIfIt = std::find_if(symbols.begin(), symbols.end(), [&](const auto& _symbol) { return _symbol == symbol; });

        if (findIfIt != symbols.end()) throw DuplicateSymbolException();
        
        symbols.push_back(symbol);
    
        symbolKeyMap_[symbol->key()] = symbol;
    }

    void add(std::shared_ptr<FunctionSymbol> symbol)
    {
        add(std::static_pointer_cast<Symbol>(symbol));
        
        auto& symbols = functionSymbolMap_[symbol->name()];

        const auto findIfIt = std::find_if(symbols.begin(), symbols.end(), [&](const auto& _symbol) { return _symbol == symbol; });

        if (findIfIt != symbols.end()) throw DuplicateSymbolException();

        symbols.push_back(symbol);
        
        functionSymbolKeyMap_[symbol->key()] = symbol;
    }

    void add(std::shared_ptr<ClassSymbol> symbol)
    {
        add(std::static_pointer_cast<Symbol>(symbol));

        auto& symbols = classSymbolMap_[symbol->name()];

        const auto findIfIt = std::find_if(symbols.begin(), symbols.end(), [&](const auto& _symbol) { return _symbol == symbol; });

        if (findIfIt != symbols.end()) throw DuplicateSymbolException();

        symbols.push_back(symbol);
        
        classSymbolKeyMap_[symbol->key()] = symbol;
    }

    void add(std::shared_ptr<ArraySymbol> symbol)
    {
        add(std::static_pointer_cast<Symbol>(symbol));

        auto& symbols = arraySymbolMap_[symbol->name()];

        const auto findIfIt = std::find_if(symbols.begin(), symbols.end(), [&](const auto& _symbol) { return _symbol == symbol; });

        if (findIfIt != symbols.end()) throw DuplicateSymbolException();

        symbols.push_back(symbol);
        
        arraySymbolKeyMap_[symbol->key()] = symbol;
    }

private:
    SymbolTable* parent_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<Symbol>>> symbolMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<FunctionSymbol>>> functionSymbolMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<ArraySymbol>>> arraySymbolMap_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<ClassSymbol>>> classSymbolMap_;
    
    std::unordered_map<std::string, std::shared_ptr<Symbol>> symbolKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<ArraySymbol>> arraySymbolKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<ClassSymbol>> classSymbolKeyMap_;
    std::unordered_map<std::string, std::shared_ptr<FunctionSymbol>> functionSymbolKeyMap_;
};

}

#endif //ICE_SCRIPT_ANALYZER_SYMBOLTABLE_HPP
