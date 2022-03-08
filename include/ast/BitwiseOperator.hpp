#ifndef ICE_SCRIPT_BITWISEOPERATOR_HPP
#define ICE_SCRIPT_BITWISEOPERATOR_HPP

namespace ice_script { namespace ast {

enum class BitwiseOperator
{
    COMPLEMENT,
    AND,
    OR,
    XOR,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    ARITHMETIC_RIGHT_SHIFT,
};

}}

#endif //ICE_SCRIPT_BITWISEOPERATOR_HPP
