#ifndef ICE_SCRIPT_ASG_IF_HPP
#define ICE_SCRIPT_ASG_IF_HPP

#include <string>

#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

namespace ice_script { namespace asg {

// IF            ::= 'if' '(' ASSIGN ')' STATEMENT ['else' STATEMENT]

struct If
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_IF_HPP