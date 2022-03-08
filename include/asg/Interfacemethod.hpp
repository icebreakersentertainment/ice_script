#ifndef ICE_SCRIPT_ASG_INTERFACEMETHOD_HPP
#define ICE_SCRIPT_ASG_INTERFACEMETHOD_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Parameterlist.hpp"

namespace ice_script { namespace asg {

// INTFMTHD      ::= TYPE ['&'] IDENTIFIER PARAMLIST ['const'] ';'

struct Interfacemethod
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_INTERFACEMETHOD_HPP