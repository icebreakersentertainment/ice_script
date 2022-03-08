#ifndef ICE_SCRIPT_INTEGER16_HPP
#define ICE_SCRIPT_INTEGER16_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct Integer16
{
    std::shared_ptr<Type> type;
    int16_t value;
};

}}

#endif //ICE_SCRIPT_INTEGER16_HPP
