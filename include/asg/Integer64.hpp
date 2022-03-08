#ifndef ICE_SCRIPT_INTEGER64_HPP
#define ICE_SCRIPT_INTEGER64_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct Integer64
{
    std::shared_ptr<Type> type;
    int64_t value;
};

}}

#endif //ICE_SCRIPT_INTEGER64_HPP
