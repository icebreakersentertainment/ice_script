#ifndef ICE_SCRIPT_ASG_INTERFACE_HPP
#define ICE_SCRIPT_ASG_INTERFACE_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Virtualproperatorerty.hpp"
#include "asg/Interfacemethod.hpp"

namespace ice_script { namespace asg {

// INTERFACE     ::= {'external' | 'shared'} 'interface' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | INTFMTHD} '}'))

struct Interface
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_INTERFACE_HPP