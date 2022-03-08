#ifndef ICE_SCRIPT_ASG_EXPRESSION_HPP
#define ICE_SCRIPT_ASG_EXPRESSION_HPP

#include <string>

namespace ice_script { namespace asg {

struct Expressionterm;
struct Expressionoperatorerty;

// EXPR          ::= EXPRTERM {EXPROP EXPRTERM}
struct Expression
{
    boost::recursive_wrapper<Expressionterm> expressionterm;
    std::vector<boost::tuple<boost::recursive_wrapper<Expressionoperatorerty>, boost::recursive_wrapper<Expressionterm>>> expressionOperationsAndExpressionTerms;
};

}}

#include "asg/Expressionterm.hpp"
#include "asg/Expressionoperatorerty.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSION_HPP