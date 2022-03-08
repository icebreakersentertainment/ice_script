#ifndef ICE_SCRIPT_ASG_TRY_HPP
#define ICE_SCRIPT_ASG_TRY_HPP

#include <string>

#include "asg/Statblock.hpp"

namespace ice_script { namespace asg {

// TRY           ::= 'try' STATBLOCK 'catch' STATBLOCK

struct Try
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_TRY_HPP