#ifndef ICE_SCRIPT_ASG_WHILE_HPP
#define ICE_SCRIPT_ASG_WHILE_HPP

#include <string>

namespace ice_script { namespace asg {

struct Assign;
struct Statement;

// WHILE         ::= 'while' '(' ASSIGN ')' STATEMENT
struct While
{
    boost::recursive_wrapper<Assign> assign;
    boost::recursive_wrapper<Statement> statement;
};

}}

#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

#endif //ICE_SCRIPT_ASG_WHILE_HPP