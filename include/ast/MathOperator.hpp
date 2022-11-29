#ifndef ICE_SCRIPT_MATHOPERATOR_HPP
#define ICE_SCRIPT_MATHOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class MathOperator
{
    UNKNOWN,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULOS,
    EXPONENT,
};

inline std::string toString(const MathOperator mathOperator)
{
    switch (mathOperator)
    {
        case MathOperator::UNKNOWN: return "UNKNOWN";
        case MathOperator::ADD: return "ADD";
        case MathOperator::SUBTRACT: return "SUBTRACT";
        case MathOperator::MULTIPLY: return "MULTIPLY";
        case MathOperator::DIVIDE: return "DIVIDE";
        case MathOperator::MODULOS: return "MODULOS";
        case MathOperator::EXPONENT: return "EXPONENT";

        default:
            throw InvalidArgumentException("Math operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const MathOperator mathOperator)
{
    os << "(" << boost::typeindex::type_id<MathOperator>().pretty_name() << ")[" << toString(mathOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_MATHOPERATOR_HPP
