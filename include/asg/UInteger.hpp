#ifndef ICE_SCRIPT_UINTEGER_HPP
#define ICE_SCRIPT_UINTEGER_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct UInteger : LocationInfo
{
    std::shared_ptr<Type> type;
    uint32_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER_HPP
