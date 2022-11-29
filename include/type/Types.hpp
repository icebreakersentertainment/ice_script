#ifndef ICE_SCRIPT_TYPE_TYPES_HPP
#define ICE_SCRIPT_TYPE_TYPES_HPP

#include "type/Type.hpp"
#include "type/AbstractTypeContainer.hpp"

namespace ice_script
{
 
class Types : public AbstractTypeContainer<Type>
{
public:
    Types() = default;
};
    
}

#endif /* ICE_SCRIPT_TYPE_TYPES_HPP */
