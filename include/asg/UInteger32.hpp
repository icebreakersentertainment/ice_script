#ifndef ICE_SCRIPT_UINTEGER32_HPP
#define ICE_SCRIPT_UINTEGER32_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct UInteger32 : LocationInfo
{
    std::shared_ptr<Type> type;
    uint32_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER32_HPP
