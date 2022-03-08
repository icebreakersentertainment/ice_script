#ifndef ICE_SCRIPT_ASG_PARAMETERLIST_HPP
#define ICE_SCRIPT_ASG_PARAMETERLIST_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Typemodifier.hpp"
#include "asg/Identifier.hpp"
#include "asg/Expression.hpp"

namespace ice_script { namespace asg {

// PARAMLIST     ::= '(' ['void' | (TYPE TYPEMOD [IDENTIFIER] ['=' EXPR] {',' TYPE TYPEMOD [IDENTIFIER] ['=' EXPR]})] ')'

struct Parameterlist
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_PARAMETERLIST_HPP