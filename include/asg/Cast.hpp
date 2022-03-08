#ifndef ICE_SCRIPT_ASG_CAST_HPP
#define ICE_SCRIPT_ASG_CAST_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// CAST          ::= 'cast' '<' TYPE '>' '(' ASSIGN ')'

struct Cast
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_CAST_HPP