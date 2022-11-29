#ifndef ICE_SCRIPT_INTEGER64_HPP
#define ICE_SCRIPT_INTEGER64_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Integer64 : LocationInfo
{
    std::shared_ptr<Type> type;
    int64_t value;
};

}}

#endif //ICE_SCRIPT_INTEGER64_HPP
