#ifndef ICE_SCRIPT_TYPE_FUNCTIONTYPES_HPP
#define ICE_SCRIPT_TYPE_FUNCTIONTYPES_HPP

#include <memory>
#include <vector>

#include "type/FunctionType.hpp"

#include "type/AbstractTypeContainer.hpp"

namespace ice_script
{
 
class FunctionTypes : public AbstractTypeContainer<FunctionType>
{
public:
    FunctionTypes() = default;
    
    std::vector<std::shared_ptr<FunctionType>> findByParameterTypes(const std::vector<std::shared_ptr<Type>>& parameterTypes) const;
};
    
}

#endif /* ICE_SCRIPT_TYPE_FUNCTIONTYPES_HPP */
