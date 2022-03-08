#ifndef ICE_SCRIPT_ASG_SCOPERATORE_HPP
#define ICE_SCRIPT_ASG_SCOPERATORE_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Type.hpp"

namespace ice_script { namespace asg {

// SCOPE         ::= ['::'] {IDENTIFIER '::'} [IDENTIFIER ['<' TYPE {',' TYPE} '>'] '::']

struct Scoperatore
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_SCOPERATORE_HPP