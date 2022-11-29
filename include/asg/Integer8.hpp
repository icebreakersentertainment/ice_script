#ifndef ICE_SCRIPT_ASG_INTEGER8_HPP
#define ICE_SCRIPT_ASG_INTEGER8_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Integer8 : LocationInfo
{
    std::shared_ptr<Type> type;
    int8_t value;
};

}}

#endif //ICE_SCRIPT_ASG_INTEGER8_HPP
