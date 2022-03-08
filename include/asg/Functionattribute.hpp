#ifndef ICE_SCRIPT_ASG_FUNCTIONATTRIBUTE_HPP
#define ICE_SCRIPT_ASG_FUNCTIONATTRIBUTE_HPP

#include <string>


namespace ice_script { namespace asg {

// FUNCATTR      ::= {'override' | 'final' | 'explicit' | 'property'}

struct Functionattribute
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_FUNCTIONATTRIBUTE_HPP