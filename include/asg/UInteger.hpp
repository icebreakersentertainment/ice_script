#ifndef ICE_SCRIPT_UINTEGER_HPP
#define ICE_SCRIPT_UINTEGER_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct UInteger
{
    std::shared_ptr<Type> type;
    uint32_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER_HPP
