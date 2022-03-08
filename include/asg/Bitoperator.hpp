#ifndef ICE_SCRIPT_ASG_BITOPERATOR_HPP
#define ICE_SCRIPT_ASG_BITOPERATOR_HPP

#include <string>


namespace ice_script { namespace asg {

// BITOP         ::= '&' | '|' | '^' | '<<' | '>>' | '>>>'

struct Bitoperator
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_BITOPERATOR_HPP