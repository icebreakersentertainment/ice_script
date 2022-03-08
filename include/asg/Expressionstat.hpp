#ifndef ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP

#include <string>

#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// EXPRSTAT      ::= [ASSIGN] ';'

struct Expressionstat
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP