#ifndef ICE_SCRIPT_ASG_EXPRESSIONOPERATORERTY_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONOPERATORERTY_HPP

#include <string>

#include "asg/Mathoperator.hpp"
#include "asg/Comparisonoperator.hpp"
#include "asg/Logicoperator.hpp"
#include "asg/Bitoperator.hpp"

namespace ice_script { namespace asg {

// EXPROP        ::= MATHOP | COMPOP | LOGICOP | BITOP
struct Expressionoperatorerty
{
    boost::variant<Bitoperator, Mathoperator, Comparisonoperator, Logicoperator> value;
};

}}

#endif //ICE_SCRIPT_ASG_EXPRESSIONOPERATORERTY_HPP