#ifndef ICE_SCRIPT_ASG_VARIABLEACCESS_HPP
#define ICE_SCRIPT_ASG_VARIABLEACCESS_HPP

#include <string>

#include "asg/Scoperatore.hpp"
#include "asg/Identifier.hpp"

namespace ice_script { namespace asg {

// VARACCESS     ::= SCOPE IDENTIFIER
struct Variableaccess
{
    Scoperatore scope;
    std::string name;
};

}}

#endif //ICE_SCRIPT_ASG_VARIABLEACCESS_HPP