#ifndef ICE_SCRIPT_ASG_LOGICOPERATOR_HPP
#define ICE_SCRIPT_ASG_LOGICOPERATOR_HPP

#include <string>


namespace ice_script { namespace asg {

// LOGICOP       ::= '&&' | '||' | '^^' | 'and' | 'or' | 'xor'

struct Logicoperator
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_LOGICOPERATOR_HPP