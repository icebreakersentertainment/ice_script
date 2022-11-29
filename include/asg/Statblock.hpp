#ifndef ICE_SCRIPT_ASG_STATBLOCK_HPP
#define ICE_SCRIPT_ASG_STATBLOCK_HPP

#include <string>

#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

struct Variable;
struct Statement;

// STATBLOCK     ::= '{' {VAR | STATEMENT} '}'
struct Statblock : LocationInfo
{
    std::vector<boost::variant<monostate, boost::recursive_wrapper<Variable>, boost::recursive_wrapper<Statement>>> values;
};

}}

#include "asg/Variable.hpp"
#include "asg/Statement.hpp"

#endif //ICE_SCRIPT_ASG_STATBLOCK_HPP