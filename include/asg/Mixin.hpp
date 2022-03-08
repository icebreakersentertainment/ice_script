#ifndef ICE_SCRIPT_ASG_MIXIN_HPP
#define ICE_SCRIPT_ASG_MIXIN_HPP

#include <string>

#include "asg/Class.hpp"

namespace ice_script { namespace asg {

// MIXIN         ::= 'mixin' CLASS

struct Mixin
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_MIXIN_HPP