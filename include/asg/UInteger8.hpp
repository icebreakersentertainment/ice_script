#ifndef ICE_SCRIPT_UINTEGER8_HPP
#define ICE_SCRIPT_UINTEGER8_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct UInteger8 : LocationInfo
{
    std::shared_ptr<Type> type;
    uint8_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER8_HPP
