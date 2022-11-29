#include "symbol/OperatorSymbols.hpp"

#include "type/OperatorType.hpp"

namespace ice_script
{

template class AbstractSymbolContainer<OperatorSymbol>;
// template void AbstractSymbolContainer<OperatorSymbol>::add(std::shared_ptr<OperatorSymbol> type);
// template void AbstractSymbolContainer<OperatorSymbol>::add(const std::vector<std::shared_ptr<OperatorSymbol>>& types);
// template std::vector<std::shared_ptr<OperatorSymbol>> AbstractSymbolContainer<OperatorSymbol>::find(const std::string& name) const;
// template std::shared_ptr<OperatorSymbol> AbstractSymbolContainer<OperatorSymbol>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<OperatorSymbol>>& AbstractSymbolContainer<OperatorSymbol>::getAll() const;

std::vector<std::shared_ptr<OperatorSymbol>> OperatorSymbols::find(const OperatorTypeId operatorTypeId) const
{
    std::vector<std::shared_ptr<OperatorSymbol>> result{};
        
    std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& operatorSymbol) {
        const auto& operatorType = std::dynamic_pointer_cast<OperatorType>(operatorSymbol->type());
        
        ICE_SCRIPT_ASSERT(operatorType);
        
        return operatorType->operatorTypeId() == operatorTypeId;
    });
    
    return result;
}

std::vector<std::shared_ptr<OperatorSymbol>> OperatorSymbols::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
{
    std::vector<std::shared_ptr<OperatorSymbol>> result{};
        
    std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& operatorSymbol) {
        if (operatorSymbol->parameters().size() != parameterTypes.size()) return false;
        
        for (size_t i = 0; i < operatorSymbol->parameters().size(); ++i)
        {
            const auto& parameterType1 = operatorSymbol->parameters()[i]->type();
            const auto& parameterType2 = parameterTypes[i];
            
            if (parameterType1 != parameterType2) return false;
        }
        
        return true;
    });
    
    return result;
}
    
}

#include "symbol/AbstractSymbolContainer.inl"