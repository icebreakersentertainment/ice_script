#ifndef ICE_SCRIPT_ASG_CONTINUE_HPP
#define ICE_SCRIPT_ASG_CONTINUE_HPP

#include <string>


namespace ice_script { namespace asg {

// CONTINUE      ::= 'continue' ';'

struct Continue
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_CONTINUE_HPP