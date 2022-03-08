#ifndef ICE_SCRIPT_ASG_MATHOPERATOR_HPP
#define ICE_SCRIPT_ASG_MATHOPERATOR_HPP

#include <string>

#include "ast/MathOperator.hpp"

namespace ice_script { namespace asg {

// MATHOP        ::= '+' | '-' | '*' | '/' | '' | '**'
struct Mathoperator
{
    ast::MathOperator mathOperator;
};

}}

#endif //ICE_SCRIPT_ASG_MATHOPERATOR_HPP