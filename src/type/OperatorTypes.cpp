// #include "type/OperatorTypes.hpp"

// #include "type/OperatorType.hpp"

// #include "exceptions/InvalidArgumentException.hpp"

// namespace ice_script
// {
 
// void OperatorTypes::add(std::shared_ptr<OperatorType> operatorType)
// {
//     const auto type = findByKey(operatorType->key());
    
//     if (type) throw InvalidArgumentException();
    
//     container_.push_back(operatorType);
//     keyToOperatorMap_[operatorType->key()] = operatorType;
// }

// void OperatorTypes::add(const std::vector<std::shared_ptr<OperatorType>>& operatorTypes)
// {
//     for (const auto& operatorType : operatorTypes)
//     {
//         add(operatorType);
//     }
// }

// std::vector<std::shared_ptr<OperatorType>> OperatorTypes::find(const std::string& name) const
// {
//     std::vector<std::shared_ptr<OperatorType>> result{};
    
//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& operatorType) {
//         return operatorType->name() == name;
//     });
    
//     return result;
// }

// std::vector<std::shared_ptr<OperatorType>> OperatorTypes::find(const OperatorTypeId operatorTypeId) const
// {
//     std::vector<std::shared_ptr<OperatorType>> results{};

//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(results), [=](const auto& _operator) {
//         return _operator->operatorTypeId() == operatorTypeId;
//     });

//     return results;
// }

// std::shared_ptr<OperatorType> OperatorTypes::findByKey(const std::string& key) const
// {
//     const auto it = keyToOperatorMap_.find(key);
    
//     return (it != keyToOperatorMap_.end() ? it->second : nullptr);
    
//     // std::vector<std::shared_ptr<OperatorType>> result{};
    
//     // const auto it = std::find_if(container_.begin(), container_.end(), [&](const auto& operatorType) {
//     //     return operatorType->key() == key;
//     // });
    
//     // return (it != container_.end() ? *it : nullptr);
// }

// std::vector<std::shared_ptr<OperatorType>> OperatorTypes::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
// {
//     std::vector<std::shared_ptr<OperatorType>> result{};
    
//     std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& operatorType) {
//         if (operatorType->parameters().size() != parameterTypes.size()) return false;
        
//         for (size_t i = 0; i < operatorType->parameters().size(); ++i)
//         {
//             const auto& parameterType1 = operatorType->parameters()[i];
//             const auto& parameterType2 = parameterTypes[i];
            
//             if (parameterType1 != parameterType2) return false;
//         }
        
//         return true;
//     });
    
//     return result;
// }

// const std::vector<std::shared_ptr<OperatorType>>& OperatorTypes::getAll() const
// {
//     return container_;
// }
    
// }


#include "type/OperatorTypes.hpp"

#include "type/OperatorType.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script
{

template class AbstractTypeContainer<OperatorType>;
// template void AbstractTypeContainer<OperatorType>::add(std::shared_ptr<OperatorType> type);
// template void AbstractTypeContainer<OperatorType>::add(const std::vector<std::shared_ptr<OperatorType>>& types);
// template std::vector<std::shared_ptr<OperatorType>> AbstractTypeContainer<OperatorType>::find(const std::string& name) const;
// template std::shared_ptr<OperatorType> AbstractTypeContainer<OperatorType>::findByKey(const std::string& key) const;
// template const std::vector<std::shared_ptr<OperatorType>>& AbstractTypeContainer<OperatorType>::getAll() const;

std::vector<std::shared_ptr<OperatorType>> OperatorTypes::find(const OperatorTypeId operatorTypeId) const
{
    std::vector<std::shared_ptr<OperatorType>> results{};

    std::copy_if(container_.begin(), container_.end(), std::back_inserter(results), [=](const auto& _operator) {
        return _operator->operatorTypeId() == operatorTypeId;
    });

    return results;
}

std::vector<std::shared_ptr<OperatorType>> OperatorTypes::findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const
{
    std::vector<std::shared_ptr<OperatorType>> result{};
    
    std::copy_if(container_.begin(), container_.end(), std::back_inserter(result), [&](const auto& operatorType) {
        if (operatorType->parameters().size() != parameterTypes.size()) return false;
        
        for (size_t i = 0; i < operatorType->parameters().size(); ++i)
        {
            const auto& parameterType1 = operatorType->parameters()[i];
            const auto& parameterType2 = parameterTypes[i];
            
            if (parameterType1 != parameterType2) return false;
        }
        
        return true;
    });
    
    return result;
}
    
}

#include "type/AbstractTypeContainer.inl"