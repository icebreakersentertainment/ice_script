#ifndef ICE_SCRIPT_ASG_STRING_HPP
#define ICE_SCRIPT_ASG_STRING_HPP

#include <string>


namespace ice_script { namespace asg {

// STRING        ::= single token:  single quoted ', double quoted ", or heredoc multi-line string """

struct String
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_STRING_HPP