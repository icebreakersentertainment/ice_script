#ifndef ICE_SCRIPT_TYPE_OPERATORTYPES_HPP
#define ICE_SCRIPT_TYPE_OPERATORTYPES_HPP

// #include <memory>
// #include <unordered_map>

// // #include "type/OperatorType.hpp"

// #include "type/OperatorTypeId.hpp"

// #include "detail/AbstractContainer.hpp"

// #include "exceptions/InvalidArgumentException.hpp"

// namespace ice_script
// {
 
// class Type;
// class OperatorType;
 
// class OperatorTypes : public detail::AbstractContainer<std::shared_ptr<OperatorType>>
// {
// public:
//     OperatorTypes() = default;
    
//     void add(std::shared_ptr<OperatorType> operatorType);
//     void add(const std::vector<std::shared_ptr<OperatorType>>& operatorTypes);
    
//     std::vector<std::shared_ptr<OperatorType>> find(const std::string& name) const;
//     std::vector<std::shared_ptr<OperatorType>> find(const OperatorTypeId operatorTypeId) const;
    
//     std::shared_ptr<OperatorType> findByKey(const std::string& key) const;
    
//     std::vector<std::shared_ptr<OperatorType>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
    
//     const std::vector<std::shared_ptr<OperatorType>>& getAll() const;
    
// protected:
//     std::unordered_map<std::string, std::shared_ptr<OperatorType>> keyToOperatorMap_;
// };
    
// }

#include <memory>
#include <unordered_map>

// #include "type/OperatorType.hpp"

#include "type/OperatorTypeId.hpp"
#include "type/AbstractTypeContainer.hpp"

namespace ice_script
{
 
class Type;
class OperatorType;
 
class OperatorTypes : public AbstractTypeContainer<OperatorType>
{
public:
    OperatorTypes() = default;
    
    std::vector<std::shared_ptr<OperatorType>> find(const OperatorTypeId operatorTypeId) const;
    
    std::vector<std::shared_ptr<OperatorType>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const; 
    
protected:
    std::unordered_map<OperatorTypeId, std::shared_ptr<OperatorType>> operatorTypeIdToOperatorMap_;
};
    
}

#endif /* ICE_SCRIPT_TYPE_OPERATORTYPES_HPP */
