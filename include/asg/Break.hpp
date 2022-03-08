#ifndef ICE_SCRIPT_ASG_BREAK_HPP
#define ICE_SCRIPT_ASG_BREAK_HPP

#include <string>


namespace ice_script { namespace asg {

// BREAK         ::= 'break' ';'

struct Break
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_BREAK_HPP