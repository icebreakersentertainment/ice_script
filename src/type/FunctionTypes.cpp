#include "type/FunctionTypes.hpp"

namespace ice_script
{

template class AbstractTypeContainer<FunctionType>;
// template void AbstractTypeContainer<FunctionType>::add(std::shared_ptr<FunctionType> type);
// template void AbstractTypeContainer<FunctionType>::add(const std::vector<std::shared_ptr<FunctionType>>& types);
// template std::vector<std::shared_ptr<FunctionType>> AbstractTypeContainer<FunctionType>::find(const std::string& name) const;
// template std::shared_ptr<FunctionType> AbstractTypeContainer<FunctionType>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<FunctionType>>& AbstractTypeContainer<FunctionType>::getAll() const;

std::vector<std::shared_ptr<FunctionType>> FunctionTypes::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
{
    std::vector<std::shared_ptr<FunctionType>> result{};
        
    std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& functionType) {
        if (functionType->parameters().size() != parameterTypes.size()) return false;
        
        for (size_t i = 0; i < functionType->parameters().size(); ++i)
        {
            const auto& parameterType1 = functionType->parameters()[i];
            const auto& parameterType2 = parameterTypes[i];
            
            if (parameterType1 != parameterType2) return false;
        }
        
        return true;
    });
    
    return result;
}
    
}

#include "type/AbstractTypeContainer.inl"