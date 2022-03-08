#ifndef ICE_SCRIPT_INTEGER32_HPP
#define ICE_SCRIPT_INTEGER32_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct Integer32
{
    std::shared_ptr<Type> type;
    int32_t value;
};

}}

#endif //ICE_SCRIPT_INTEGER32_HPP
