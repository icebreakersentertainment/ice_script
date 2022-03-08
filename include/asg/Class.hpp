#ifndef ICE_SCRIPT_ASG_CLASS_HPP
#define ICE_SCRIPT_ASG_CLASS_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Virtualproperatorerty.hpp"
#include "asg/Function.hpp"
#include "asg/Variable.hpp"
#include "asg/Functiondefinition.hpp"

namespace ice_script { namespace asg {

// CLASS         ::= {'shared' | 'abstract' | 'final' | 'external'} 'class' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | FUNC | VAR | FUNCDEF} '}'))

struct Class
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_CLASS_HPP