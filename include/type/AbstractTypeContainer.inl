#include "type/AbstractTypeContainer.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script
{

template <typename T>
void AbstractTypeContainer<T>::add(std::shared_ptr<T> type)
{
    if (findByKey(type->key())) throw InvalidArgumentException();
    
    this->container_.push_back(type);
    keyToTypeMap_[type->key()] = type;
    nameToTypeMap_[type->name()].push_back(type);
}

template <typename T>
void AbstractTypeContainer<T>::add(const std::vector<std::shared_ptr<T>>& types)
{
    for (const auto& type : types) add(type);
}

template <typename T>
std::vector<std::shared_ptr<T>> AbstractTypeContainer<T>::find(const std::string& name) const
{
    const auto it = nameToTypeMap_.find(name);
    
    return (it != nameToTypeMap_.end() ? it->second : std::vector<std::shared_ptr<T>>{});
    
    // std::vector<std::shared_ptr<T>> result{};
    
    // std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& type) {
    //     return type->name() == name;
    // });
    
    // return result;
}

// template <typename T>
// std::vector<std::shared_ptr<T>> AbstractTypeContainer<T>::find(const OperatorTypeId operatorTypeId) const
// {
//     std::vector<std::shared_ptr<T>> results{};

//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(results), [=](const auto& _operator) {
//         return _operator->operatorTypeId() == operatorTypeId;
//     });

//     return results;
// }

template <typename T>
std::shared_ptr<T> AbstractTypeContainer<T>::findByKey(const std::string& key) const
{
    const auto it = keyToTypeMap_.find(key);
    
    return (it != keyToTypeMap_.end() ? it->second : nullptr);
    
    // std::vector<std::shared_ptr<T>> result{};
    
    // const auto it = std::find_if(container_.begin(), container_.end(), [&](const auto& type) {
    //     return type->key() == key;
    // });
    
    // return (it != container_.end() ? *it : nullptr);
}

// template <typename T>
// std::vector<std::shared_ptr<T>> AbstractTypeContainer<T>::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
// {
//     std::vector<std::shared_ptr<T>> result{};
    
//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& type) {
//         if (type->parameters().size() != parameterTypes.size()) return false;
        
//         for (size_t i = 0; i < type->parameters().size(); ++i)
//         {
//             const auto& parameterType1 = type->parameters()[i];
//             const auto& parameterType2 = parameterTypes[i];
            
//             if (parameterType1 != parameterType2) return false;
//         }
        
//         return true;
//     });
    
//     return result;
// }

template <typename T>
const std::vector<std::shared_ptr<T>>& AbstractTypeContainer<T>::getAll() const
{
    return this->container_;
}
    
}
