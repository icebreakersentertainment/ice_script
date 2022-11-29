#ifndef ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP
#define ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP

#include <string>

#include "ast/ComparisonOperator.hpp"

namespace ice_script { namespace asg {

// COMPOP        ::= '==' | '!=' | '<' | '<=' | '>' | '>=' | 'is' | '!is'
struct Comparisonoperator
{
    ast::ComparisonOperator comparisonOperator;
};

}}

#endif //ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP