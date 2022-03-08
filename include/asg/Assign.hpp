#ifndef ICE_SCRIPT_ASG_ASSIGN_HPP
#define ICE_SCRIPT_ASG_ASSIGN_HPP

#include <string>

#include "asg/Assignoperator.hpp"

namespace ice_script { namespace asg {

struct Condition;

// ASSIGN        ::= CONDITION [ ASSIGNOP ASSIGN ]
struct Assign
{
    boost::recursive_wrapper<Condition> condition;
    boost::optional<boost::tuple<Assignoperator, boost::recursive_wrapper<Assign>>> assignopAssign;
};

}}

#include "asg/Condition.hpp"

#endif //ICE_SCRIPT_ASG_ASSIGN_HPP