#ifndef ICE_SCRIPT_ASG_CASE_HPP
#define ICE_SCRIPT_ASG_CASE_HPP

#include <string>

#include "asg/Expression.hpp"
#include "asg/Statement.hpp"

namespace ice_script { namespace asg {

// CASE          ::= (('case' EXPR) | 'default') ':' {STATEMENT}

struct Case
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_CASE_HPP