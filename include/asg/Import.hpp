#ifndef ICE_SCRIPT_ASG_IMPORT_HPP
#define ICE_SCRIPT_ASG_IMPORT_HPP

#include <string>

#include "type/Type.hpp"
#include "asg/Identifier.hpp"
#include "asg/Parameterlist.hpp"
#include "asg/Functionattribute.hpp"
#include "asg/String.hpp"

namespace ice_script { namespace asg {

// IMPORT        ::= 'import' TYPE ['&'] IDENTIFIER PARAMLIST FUNCATTR 'from' STRING ';'

struct Import
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_IMPORT_HPP