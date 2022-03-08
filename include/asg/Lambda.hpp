#ifndef ICE_SCRIPT_ASG_LAMBDA_HPP
#define ICE_SCRIPT_ASG_LAMBDA_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Typemodifier.hpp"
#include "asg/Identifier.hpp"
#include "asg/Statblock.hpp"

namespace ice_script { namespace asg {

// LAMBDA        ::= 'function' '(' [[TYPE TYPEMOD] IDENTIFIER {',' [TYPE TYPEMOD] IDENTIFIER}] ')' STATBLOCK

struct Lambda
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_LAMBDA_HPP