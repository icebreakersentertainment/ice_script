#ifndef ICE_SCRIPT_UINTEGER64_HPP
#define ICE_SCRIPT_UINTEGER64_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct UInteger64
{
    std::shared_ptr<Type> type;
    uint64_t value;
};

}}

#endif //ICE_SCRIPT_UINTEGER64_HPP
