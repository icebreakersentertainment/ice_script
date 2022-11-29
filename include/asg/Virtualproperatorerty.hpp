#ifndef ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP
#define ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP

#include <string>

#include "type/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Functionattribute.hpp"
#include "asg/Statblock.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

// VIRTPROP      ::= ['private' | 'protected'] TYPE ['&'] IDENTIFIER '{' {('get' | 'set') ['const'] FUNCATTR (STATBLOCK | ';')} '}'

struct Virtualproperatorerty : LocationInfo
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_VIRTUALPROPERATORERTY_HPP