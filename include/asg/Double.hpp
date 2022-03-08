#ifndef ICE_SCRIPT_DOUBLE_HPP
#define ICE_SCRIPT_DOUBLE_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

struct Double
{
    std::shared_ptr<Type> type;
    double value;
};

}}

#endif //ICE_SCRIPT_DOUBLE_HPP
