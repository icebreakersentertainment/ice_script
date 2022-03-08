#ifndef ICE_SCRIPT_ASG_NAMESPACE_HPP
#define ICE_SCRIPT_ASG_NAMESPACE_HPP

#include <string>

#include "asg/Identifier.hpp"

namespace ice_script { namespace asg {

// NAMESPACE     ::= 'namespace' IDENTIFIER {'::' IDENTIFIER} '{' SCRIPT '}'

struct Namespace
{
    std::string value;
};

}}

#include "asg/Script.hpp"

#endif //ICE_SCRIPT_ASG_NAMESPACE_HPP