#ifndef ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP
#define ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP

#include <string>

#include "type/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Parameterlist.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

// FUNCDEF       ::= {'external' | 'shared'} 'funcdef' TYPE ['&'] IDENTIFIER PARAMLIST ';'

struct Functiondefinition : LocationInfo
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_FUNCTIONDEFINITION_HPP