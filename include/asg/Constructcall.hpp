#ifndef ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP
#define ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Arglist.hpp"

namespace ice_script { namespace asg {

// CONSTRUCTCALL ::= TYPE ARGLIST

struct Constructcall
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP