#include "symbol/FunctionSymbols.hpp"

namespace ice_script
{

template class AbstractSymbolContainer<FunctionSymbol>;
// template void AbstractSymbolContainer<FunctionSymbol>::add(std::shared_ptr<FunctionSymbol> type);
// template void AbstractSymbolContainer<FunctionSymbol>::add(const std::vector<std::shared_ptr<FunctionSymbol>>& types);
// template std::vector<std::shared_ptr<FunctionSymbol>> AbstractSymbolContainer<FunctionSymbol>::find(const std::string& name) const;
// template std::shared_ptr<FunctionSymbol> AbstractSymbolContainer<FunctionSymbol>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<FunctionSymbol>>& AbstractSymbolContainer<FunctionSymbol>::getAll() const;

std::vector<std::shared_ptr<FunctionSymbol>> FunctionSymbols::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
{
    std::vector<std::shared_ptr<FunctionSymbol>> result{};
        
    std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& functionSymbol) {
        if (functionSymbol->parameters().size() != parameterTypes.size()) return false;
        
        for (size_t i = 0; i < functionSymbol->parameters().size(); ++i)
        {
            const auto& parameterType1 = functionSymbol->parameters()[i]->type();
            const auto& parameterType2 = parameterTypes[i];
            
            if (parameterType1 != parameterType2) return false;
        }
        
        return true;
    });
    
    return result;
}
    
}

#include "symbol/AbstractSymbolContainer.inl"