#ifndef ICE_SCRIPT_ASSIGNOPERATOR_HPP
#define ICE_SCRIPT_ASSIGNOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class AssignOperator
{
    UNKNOWN,
    EQUAL,
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULOS,
    EXPONENT,
    AND,
    OR,
    XOR,
    LEFT_SHIFT,
    RIGHT_SHIFT,
    ARITHMETIC_RIGHT_SHIFT,
};

inline std::string toString(const AssignOperator assignOperator)
{
    switch (assignOperator)
    {
        case AssignOperator::UNKNOWN: return "UNKNOWN";
        case AssignOperator::EQUAL: return "EQUAL";
        case AssignOperator::ADD: return "ADD";
        case AssignOperator::SUBTRACT: return "SUBTRACT";
        case AssignOperator::MULTIPLY: return "MULTIPLY";
        case AssignOperator::DIVIDE: return "DIVIDE";
        case AssignOperator::MODULOS: return "MODULOS";
        case AssignOperator::EXPONENT: return "EXPONENT";
        case AssignOperator::AND: return "AND";
        case AssignOperator::OR: return "OR";
        case AssignOperator::XOR: return "XOR";
        case AssignOperator::LEFT_SHIFT: return "LEFT_SHIFT";
        case AssignOperator::RIGHT_SHIFT: return "RIGHT_SHIFT";
        case AssignOperator::ARITHMETIC_RIGHT_SHIFT: return "ARITHMETIC_RIGHT_SHIFT";

        default:
            throw InvalidArgumentException("Assign operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const AssignOperator assignOperator)
{
    os << "(" << boost::typeindex::type_id<AssignOperator>().pretty_name() << ")[" << toString(assignOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_ASSIGNOPERATOR_HPP
