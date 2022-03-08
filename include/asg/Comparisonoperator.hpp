#ifndef ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP
#define ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP

#include <string>


namespace ice_script { namespace asg {

// COMPOP        ::= '==' | '!=' | '<' | '<=' | '>' | '>=' | 'is' | '!is'

struct Comparisonoperator
{
    std::string value;
};

}}

#endif //ICE_SCRIPT_ASG_COMPARISONOPERATOR_HPP