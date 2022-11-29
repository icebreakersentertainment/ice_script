#ifndef ICE_SCRIPT_ASG_RETURN_HPP
#define ICE_SCRIPT_ASG_RETURN_HPP

#include <string>

#include "asg/Assign.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

// RETURN        ::= 'return' [ASSIGN] ';'
struct Return : LocationInfo
{
    boost::optional<Assign> assignment;
};

}}

#endif //ICE_SCRIPT_ASG_RETURN_HPP