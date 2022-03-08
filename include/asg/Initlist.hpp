#ifndef ICE_SCRIPT_ASG_INITLIST_HPP
#define ICE_SCRIPT_ASG_INITLIST_HPP

#include <string>

#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// INITLIST      ::= '{' [ASSIGN | INITLIST] {',' [ASSIGN | INITLIST]} '}'

struct Initlist
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_INITLIST_HPP