#ifndef ICE_SCRIPT_ASG_PRIMATIVETYPE_HPP
#define ICE_SCRIPT_ASG_PRIMATIVETYPE_HPP

#include <string>


namespace ice_script { namespace asg {

// PRIMTYPE      ::= 'void' | 'int' | 'int8' | 'int16' | 'int32' | 'int64' | 'uint' | 'uint8' | 'uint16' | 'uint32' | 'uint64' | 'float' | 'double' | 'bool'

struct Primativetype
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_PRIMATIVETYPE_HPP