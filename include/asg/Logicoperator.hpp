#ifndef ICE_SCRIPT_ASG_LOGICOPERATOR_HPP
#define ICE_SCRIPT_ASG_LOGICOPERATOR_HPP

#include <string>

#include "ast/LogicOperator.hpp"

namespace ice_script { namespace asg {

// LOGICOP       ::= '&&' | '||' | '^^' | 'and' | 'or' | 'xor'
struct Logicoperator
{
    ast::LogicOperator logicOperator;
};

}}

#endif //ICE_SCRIPT_ASG_LOGICOPERATOR_HPP