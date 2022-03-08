#ifndef ICE_SCRIPT_ASG_SWITCH_HPP
#define ICE_SCRIPT_ASG_SWITCH_HPP

#include <string>

#include "asg/Assign.hpp"
#include "asg/Case.hpp"

namespace ice_script { namespace asg {

// SWITCH        ::= 'switch' '(' ASSIGN ')' '{' {CASE} '}'

struct Switch
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_SWITCH_HPP