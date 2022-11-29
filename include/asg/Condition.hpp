#ifndef ICE_SCRIPT_ASG_CONDITION_HPP
#define ICE_SCRIPT_ASG_CONDITION_HPP

#include <string>

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Expression;
struct Assign;

// CONDITION     ::= EXPR ['?' ASSIGN ':' ASSIGN]
struct Condition : LocationInfo
{
    Condition() = default;
    
    Condition(boost::recursive_wrapper<Expression> expression) : expression(std::move(expression))
    {}
    
    boost::recursive_wrapper<Expression> expression;
    boost::optional<
            boost::tuple<boost::recursive_wrapper<Assign>, boost::recursive_wrapper<Assign>>
    > assign;
};

}}

#include "asg/Expression.hpp"
#include "asg/Assign.hpp"

#endif //ICE_SCRIPT_ASG_CONDITION_HPP