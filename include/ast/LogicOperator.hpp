#ifndef ICE_SCRIPT_LOGICOPERATOR_HPP
#define ICE_SCRIPT_LOGICOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class LogicOperator
{
    UNKNOWN,
    AND,
    OR,
    XOR,
    NOT,
};

inline std::string toString(const LogicOperator logicOperator)
{
    switch (logicOperator)
    {
        case LogicOperator::UNKNOWN: return "UNKNOWN";
        case LogicOperator::AND: return "AND";
        case LogicOperator::OR: return "OR";
        case LogicOperator::XOR: return "XOR";
        case LogicOperator::NOT: return "NOT";

        default:
            throw InvalidArgumentException("Logic operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const LogicOperator logicOperator)
{
    os << "(" << boost::typeindex::type_id<LogicOperator>().pretty_name() << ")[" << toString(logicOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_LOGICOPERATOR_HPP
