#ifndef ICE_SCRIPT_ASG_EXPRESSIONPREOPERATOR_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONPREOPERATOR_HPP

#include <string>


namespace ice_script { namespace asg {

// EXPRPREOP     ::= '-' | '+' | '!' | '++' | '--' | '~' | '@'

struct Expressionpreoperator
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_EXPRESSIONPREOPERATOR_HPP