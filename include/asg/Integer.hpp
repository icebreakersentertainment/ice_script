#ifndef ICE_SCRIPT_INTEGER_HPP
#define ICE_SCRIPT_INTEGER_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Integer : LocationInfo
{
    std::shared_ptr<Type> type;
    int32_t value;
};

}}

#endif //ICE_SCRIPT_INTEGER_HPP
