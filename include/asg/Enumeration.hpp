#ifndef ICE_SCRIPT_ASG_ENUMERATION_HPP
#define ICE_SCRIPT_ASG_ENUMERATION_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Expression.hpp"

namespace ice_script { namespace asg {

// ENUM          ::= {'shared' | 'external'} 'enum' IDENTIFIER (';' | ('{' IDENTIFIER ['=' EXPR] {',' IDENTIFIER ['=' EXPR]} '}'))

struct Enumeration
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_ENUMERATION_HPP