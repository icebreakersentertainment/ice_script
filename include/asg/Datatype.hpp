#ifndef ICE_SCRIPT_ASG_DATATYPE_HPP
#define ICE_SCRIPT_ASG_DATATYPE_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Primativetype.hpp"

namespace ice_script { namespace asg {

// DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')

struct Datatype
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_DATATYPE_HPP