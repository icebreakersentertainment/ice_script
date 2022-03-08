#ifndef ICE_SCRIPT_ASG_DOWHILE_HPP
#define ICE_SCRIPT_ASG_DOWHILE_HPP

#include <string>

#include "asg/Statement.hpp"
#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// DOWHILE       ::= 'do' STATEMENT 'while' '(' ASSIGN ')' ';'

struct Dowhile
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_DOWHILE_HPP