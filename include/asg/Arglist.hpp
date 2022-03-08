#ifndef ICE_SCRIPT_ASG_ARGLIST_HPP
#define ICE_SCRIPT_ASG_ARGLIST_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// ARGLIST       ::= '(' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':'] ASSIGN} ')'

struct Arglist
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_ARGLIST_HPP