#ifndef ICE_SCRIPT_ASG_TYPEMODIFIER_HPP
#define ICE_SCRIPT_ASG_TYPEMODIFIER_HPP

#include <string>


namespace ice_script { namespace asg {

// TYPEMOD       ::= ['&' ['in' | 'out' | 'inout']]

struct Typemodifier
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_TYPEMODIFIER_HPP