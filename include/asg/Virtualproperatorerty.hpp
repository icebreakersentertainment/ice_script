#ifndef ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP
#define ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Functionattribute.hpp"
#include "asg/Statblock.hpp"

namespace ice_script { namespace asg {

// VIRTPROP      ::= ['private' | 'protected'] TYPE ['&'] IDENTIFIER '{' {('get' | 'set') ['const'] FUNCATTR (STATBLOCK | ';')} '}'

struct Virtualproperatorerty
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP