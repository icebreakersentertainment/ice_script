#ifndef ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP
#define ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP

#include <string>

#include "ast/AssignOperator.hpp"

namespace ice_script { namespace asg {

// ASSIGNOP      ::= '=' | '+=' | '-=' | '*=' | '/=' | '|=' | '&=' | '^=' | '%=' | '**=' | '<<=' | '>>=' | '>>>='
struct Assignoperator
{
    ast::AssignOperator assignOperator;
};

}}

#endif //ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP