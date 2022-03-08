#ifndef ICE_SCRIPT_UINTEGER32_HPP
#define ICE_SCRIPT_UINTEGER32_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct UInteger32
{
    std::shared_ptr<Type> type;
    uint32_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER32_HPP
