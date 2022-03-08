#ifndef ICE_SCRIPT_COMPARISONOPERATOR_HPP
#define ICE_SCRIPT_COMPARISONOPERATOR_HPP

namespace ice_script { namespace ast {

enum class ComparisonOperator
{
    EQUALS,
    NOT_EQUALS,
    LESS_THAN,
    LESS_THAN_OR_EQUALS,
    GREATER_THAN,
    GREATER_THAN_OR_EQUALS,
    IS,
    IS_NOT
};

}}

#endif //ICE_SCRIPT_COMPARISONOPERATOR_HPP
