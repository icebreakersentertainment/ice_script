#ifndef ICE_SCRIPT_BITWISEOPERATOR_HPP
#define ICE_SCRIPT_BITWISEOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class BitwiseOperator
{
    UNKNOWN,
    COMPLEMENT,
    AND,
    OR,
    XOR,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    ARITHMETIC_RIGHT_SHIFT,
};

inline std::string toString(const BitwiseOperator bitwiseOperator)
{
    switch (bitwiseOperator)
    {
        case BitwiseOperator::UNKNOWN: return "UNKNOWN";
        case BitwiseOperator::COMPLEMENT: return "BITWISE_COMPLEMENT";
        case BitwiseOperator::AND: return "BITWISE_AND";
        case BitwiseOperator::OR: return "BITWISE_OR";
        case BitwiseOperator::XOR: return "BITWISE_XOR";
        case BitwiseOperator::LEFT_SHIFT: return "BITWISE_LEFT_SHIFT";
        case BitwiseOperator::RIGHT_SHIFT: return "BITWISE_RIGHT_SHIFT";
        case BitwiseOperator::ARITHMETIC_RIGHT_SHIFT: return "BITWISE_ARITHMETIC_RIGHT_SHIFT";

        default:
            throw InvalidArgumentException("Bitwise operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const BitwiseOperator bitwiseOperator)
{
    os << "(" << boost::typeindex::type_id<BitwiseOperator>().pretty_name() << ")[" << toString(bitwiseOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_BITWISEOPERATOR_HPP
