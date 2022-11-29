#ifndef ICE_SCRIPT_COMPARISONOPERATOR_HPP
#define ICE_SCRIPT_COMPARISONOPERATOR_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class ComparisonOperator
{
    UNKNOWN,
    EQUALS,
    NOT_EQUALS,
    LESS_THAN,
    LESS_THAN_OR_EQUALS,
    GREATER_THAN,
    GREATER_THAN_OR_EQUALS,
    IS,
    IS_NOT
};

inline std::string toString(const ComparisonOperator comparisonOperator)
{
    switch (comparisonOperator)
    {
        case ComparisonOperator::UNKNOWN: return "UNKNOWN";
        case ComparisonOperator::EQUALS: return "EQUALS";
        case ComparisonOperator::NOT_EQUALS: return "NOT_EQUALS";
        case ComparisonOperator::LESS_THAN: return "LESS_THAN";
        case ComparisonOperator::LESS_THAN_OR_EQUALS: return "LESS_THAN_OR_EQUALS";
        case ComparisonOperator::GREATER_THAN: return "GREATER_THAN";
        case ComparisonOperator::GREATER_THAN_OR_EQUALS: return "GREATER_THAN_OR_EQUALS";
        case ComparisonOperator::IS: return "IS";
        case ComparisonOperator::IS_NOT: return "IS_NOT";

        default:
            throw InvalidArgumentException("Comparison operator not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const ComparisonOperator comparisonOperator)
{
    os << "(" << boost::typeindex::type_id<ComparisonOperator>().pretty_name() << ")[" << toString(comparisonOperator) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_COMPARISONOPERATOR_HPP
