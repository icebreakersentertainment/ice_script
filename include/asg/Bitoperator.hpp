#ifndef ICE_SCRIPT_ASG_BITOPERATOR_HPP
#define ICE_SCRIPT_ASG_BITOPERATOR_HPP

#include <string>

#include "ast/BitwiseOperator.hpp"

namespace ice_script { namespace asg {

// BITOP         ::= '&' | '|' | '^' | '<<' | '>>' | '>>>'
struct Bitoperator
{
    ast::BitwiseOperator bitwiseOperator;
};

}}

#endif //ICE_SCRIPT_ASG_BITOPERATOR_HPP