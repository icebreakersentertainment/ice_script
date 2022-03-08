#ifndef ICE_SCRIPT_ASG_FOR_HPP
#define ICE_SCRIPT_ASG_FOR_HPP

#include <string>

#include "asg/Variable.hpp"
#include "asg/Expressionstat.hpp"
#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

namespace ice_script { namespace asg {

// FOR           ::= 'for' '(' (VAR | EXPRSTAT) EXPRSTAT [ASSIGN {',' ASSIGN}] ')' STATEMENT

struct For
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_FOR_HPP