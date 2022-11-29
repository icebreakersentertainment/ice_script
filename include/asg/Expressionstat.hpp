#ifndef ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP

#include <string>

#include "asg/Assign.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

// EXPRSTAT      ::= [ASSIGN] ';'
struct Expressionstat : LocationInfo
{
    Expressionstat() = default;
    
    Expressionstat(Assign assign) : assign(std::move(assign))
    {}
    
    boost::optional<Assign> assign;
};

}}

#endif //ICE_SCRIPT_ASG_EXPRESSIONSTAT_HPP