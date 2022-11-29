#ifndef ICE_SCRIPT_ASG_ASSIGN_HPP
#define ICE_SCRIPT_ASG_ASSIGN_HPP

#include <string>

#include "asg/Assignoperator.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Condition;
struct Functioncall;

// ASSIGN        ::= CONDITION [ ASSIGNOP ASSIGN ]
struct Assign : LocationInfo
{
    Assign() = default;
    
    Assign(boost::recursive_wrapper<Condition> condition) : condition(std::move(condition))
    {}
    
    boost::recursive_wrapper<Condition> condition;
//    boost::optional<boost::tuple<Assignoperator, boost::recursive_wrapper<Assign>>> assignopAssign;
    boost::optional<boost::recursive_wrapper<Functioncall>> functioncall;
};

}}

#include "asg/Condition.hpp"
#include "asg/Functioncall.hpp"

#endif //ICE_SCRIPT_ASG_ASSIGN_HPP