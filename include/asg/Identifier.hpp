#ifndef ICE_SCRIPT_ASG_IDENTIFIER_HPP
#define ICE_SCRIPT_ASG_IDENTIFIER_HPP

#include <string>


namespace ice_script { namespace asg {

// IDENTIFIER    ::= single token:  starts with letter or _, can include any letter and digit, same as in C++

struct Identifier
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_IDENTIFIER_HPP