#ifndef ICE_SCRIPT_FLOAT_HPP
#define ICE_SCRIPT_FLOAT_HPP

#include "type/Type.hpp"

namespace ice_script { namespace asg {

struct Float
{
    std::shared_ptr<Type> type;
    float value;
};

}}

#endif //ICE_SCRIPT_FLOAT_HPP
