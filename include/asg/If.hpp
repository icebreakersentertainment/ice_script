#ifndef ICE_SCRIPT_ASG_IF_HPP
#define ICE_SCRIPT_ASG_IF_HPP

#include <string>

namespace ice_script { namespace asg {

struct Assign;
struct Statement;

// IF            ::= 'if' '(' ASSIGN ')' STATEMENT ['else' STATEMENT]
struct If
{
    boost::recursive_wrapper<Assign> assign;
    boost::recursive_wrapper<Statement> statement;
    boost::optional<boost::recursive_wrapper<Statement>> optionalStatement;
};

}}

#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

#endif //ICE_SCRIPT_ASG_IF_HPP