#ifndef ICE_SCRIPT_ASG_RETURN_HPP
#define ICE_SCRIPT_ASG_RETURN_HPP

#include <string>

#include "asg/Assign.hpp"

namespace ice_script { namespace asg {

// RETURN        ::= 'return' [ASSIGN] ';'
struct Return
{
    boost::optional<Assign> assignment;
};

}}

#endif //ICE_SCRIPT_ASG_RETURN_HPP