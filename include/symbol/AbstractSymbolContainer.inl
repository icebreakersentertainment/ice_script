#include "symbol/AbstractSymbolContainer.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script
{
    
template <typename T>
void AbstractSymbolContainer<T>::add(std::shared_ptr<T> symbol)
{
    if (findByKey(symbol->key())) throw InvalidArgumentException();
    
    this->container_.push_back(symbol);
    keyToSymbolMap_[symbol->key()] = symbol;
    nameToSymbolMap_[symbol->name()].push_back(symbol);
}

template <typename T>
void AbstractSymbolContainer<T>::add(const std::vector<std::shared_ptr<T>>& types)
{
    for (const auto& symbol : types) add(symbol);
}

template <typename T>
std::vector<std::shared_ptr<T>> AbstractSymbolContainer<T>::find(const std::string& name) const
{
    const auto it = nameToSymbolMap_.find(name);
    
    return (it != nameToSymbolMap_.end() ? it->second : std::vector<std::shared_ptr<T>>{});
    
    // std::vector<std::shared_ptr<T>> result{};
    
    // std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& symbol) {
    //     return symbol->name() == name;
    // });
    
    // return result;
}

// template <typename T>
// std::vector<std::shared_ptr<T>> AbstractSymbolContainer<T>::find(const OperatorTypeId operatorTypeId) const
// {
//     std::vector<std::shared_ptr<T>> results{};

//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(results), [=](const auto& _operator) {
//         return _operator->operatorTypeId() == operatorTypeId;
//     });

//     return results;
// }

template <typename T>
std::shared_ptr<T> AbstractSymbolContainer<T>::findByKey(const std::string& key) const
{
    const auto it = keyToSymbolMap_.find(key);
    
    return (it != keyToSymbolMap_.end() ? it->second : nullptr);
    
    // std::vector<std::shared_ptr<T>> result{};
    
    // const auto it = std::find_if(container_.begin(), container_.end(), [&](const auto& symbol) {
    //     return symbol->key() == key;
    // });
    
    // return (it != container_.end() ? *it : nullptr);
}

// template <typename T>
// std::vector<std::shared_ptr<T>> AbstractSymbolContainer<T>::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
// {
//     std::vector<std::shared_ptr<T>> result{};
    
//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& symbol) {
//         if (symbol->parameters().size() != parameterTypes.size()) return false;
        
//         for (size_t i = 0; i < symbol->parameters().size(); ++i)
//         {
//             const auto& parameterType1 = symbol->parameters()[i];
//             const auto& parameterType2 = parameterTypes[i];
            
//             if (parameterType1 != parameterType2) return false;
//         }
        
//         return true;
//     });
    
//     return result;
// }

template <typename T>
const std::vector<std::shared_ptr<T>>& AbstractSymbolContainer<T>::getAll() const
{
    return this->container_;
}
    
}
