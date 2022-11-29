#ifndef ICE_SCRIPT_DOUBLE_HPP
#define ICE_SCRIPT_DOUBLE_HPP

#include "type/Type.hpp"

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Double : LocationInfo
{
    std::shared_ptr<Type> type;
    double value;
};

}}

#endif //ICE_SCRIPT_DOUBLE_HPP
