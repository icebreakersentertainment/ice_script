#ifndef ICE_SCRIPT_ASG_WHILE_HPP
#define ICE_SCRIPT_ASG_WHILE_HPP

#include <string>

#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

namespace ice_script { namespace asg {

// WHILE         ::= 'while' '(' ASSIGN ')' STATEMENT

struct While
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_WHILE_HPP