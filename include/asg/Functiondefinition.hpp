#ifndef ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP
#define ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Parameterlist.hpp"

namespace ice_script { namespace asg {

// FUNCDEF       ::= {'external' | 'shared'} 'funcdef' TYPE ['&'] IDENTIFIER PARAMLIST ';'

struct Functiondefinition
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP