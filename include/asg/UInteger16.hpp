#ifndef ICE_SCRIPT_UINTEGER16_HPP
#define ICE_SCRIPT_UINTEGER16_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct UInteger16
{
    std::shared_ptr<Type> type;
    uint16_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER16_HPP
