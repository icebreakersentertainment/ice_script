#ifndef ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP
#define ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP

#include <string>


namespace ice_script { namespace asg {

// ASSIGNOP      ::= '=' | '+=' | '-=' | '*=' | '/=' | '|=' | '&=' | '^=' | '%=' | '**=' | '<<=' | '>>=' | '>>>='

struct Assignoperator
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_ASSIGNOPERATOR_HPP