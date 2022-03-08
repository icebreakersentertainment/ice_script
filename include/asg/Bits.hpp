#ifndef ICE_SCRIPT_ASG_BITS_HPP
#define ICE_SCRIPT_ASG_BITS_HPP

#include <string>


namespace ice_script { namespace asg {

// BITS          ::= single token:  binary 0b or 0B, octal 0o or 0O, decimal 0d or 0D, hexadecimal 0x or 0X
struct Bits
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_BITS_HPP