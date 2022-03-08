#ifndef ICE_SCRIPT_ASG_TYPEDEFINITION_HPP
#define ICE_SCRIPT_ASG_TYPEDEFINITION_HPP

#include <string>

#include "asg/Primativetype.hpp"
#include "asg/Identifier.hpp"

namespace ice_script { namespace asg {

// TYPEDEF       ::= 'typedef' PRIMTYPE IDENTIFIER ';'

struct Typedefinition
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_TYPEDEFINITION_HPP