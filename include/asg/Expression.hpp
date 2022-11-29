#ifndef ICE_SCRIPT_ASG_EXPRESSION_HPP
#define ICE_SCRIPT_ASG_EXPRESSION_HPP

#include <string>

#include "asg/LocationInfo.hpp"
#include "type/OperatorType.hpp"

namespace ice_script { namespace asg {

struct Expressionterm;
struct Expressionoperatorerty;
struct Functioncall;

struct OperatorTypeAndExpressionTerm
{
    OperatorTypeAndExpressionTerm(boost::recursive_wrapper<Expressionoperatorerty> expressionOperatorerty, boost::recursive_wrapper<Expressionterm> expressionTerm)
    :
        expressionOperatorerty(expressionOperatorerty),
        expressionTerm(expressionTerm)
    {}

    OperatorTypeAndExpressionTerm(std::shared_ptr<OperatorType> operatorType, boost::recursive_wrapper<Expressionterm> expressionTerm)
    :
        operatorType(std::move(operatorType)),
        expressionTerm(expressionTerm)
    {}

    boost::recursive_wrapper<Expressionoperatorerty> expressionOperatorerty;
    std::shared_ptr<OperatorType> operatorType;
    boost::recursive_wrapper<Expressionterm> expressionTerm;
};

// EXPR          ::= EXPRTERM {EXPROP EXPRTERM}
struct Expression : LocationInfo
{
    Expression() = default;
    
    Expression(boost::recursive_wrapper<Expressionterm> expressionterm) : expressionterm(std::move(expressionterm))
    {}
    
    boost::recursive_wrapper<Expressionterm> expressionterm;
//    std::vector<OperatorTypeAndExpressionTerm> operatorTypeAndExpressionTerms;
    boost::optional<boost::recursive_wrapper<Functioncall>> functioncall;
};

}}

#include "asg/Expressionterm.hpp"
#include "asg/Expressionoperatorerty.hpp"
#include "asg/Functioncall.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSION_HPP