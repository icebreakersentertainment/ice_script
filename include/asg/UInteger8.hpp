#ifndef ICE_SCRIPT_UINTEGER8_HPP
#define ICE_SCRIPT_UINTEGER8_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct UInteger8
{
    std::shared_ptr<Type> type;
    uint8_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER8_HPP
