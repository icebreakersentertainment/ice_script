#ifndef ICE_SCRIPT_UINTEGER64_HPP
#define ICE_SCRIPT_UINTEGER64_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct UInteger64 : LocationInfo
{
    std::shared_ptr<Type> type;
    uint64_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER64_HPP
