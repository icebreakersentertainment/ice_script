#ifndef ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP

#include <string>

#include "asg/Expressionpreoperator.hpp"
#include "asg/Expressionvalue.hpp"
#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script
{

class Type;

namespace asg
{

struct Initlist;
struct Expressionpostoperator;

struct ExprpreopsExprvalueExprpostops
{
    ExprpreopsExprvalueExprpostops() = default;

    ExprpreopsExprvalueExprpostops(std::vector<Expressionpreoperator> expressionPreoperators,
                                   Expressionvalue expressionValue,
                                   std::vector<boost::recursive_wrapper<Expressionpostoperator>> expressionPostoperators)
            :
                expressionPreoperators(std::move(expressionPreoperators)),
                expressionValue(std::move(expressionValue)),
                expressionPostoperators(std::move(expressionPostoperators))
    {}

    std::vector<Expressionpreoperator> expressionPreoperators;
    Expressionvalue expressionValue;
    std::vector<boost::recursive_wrapper<Expressionpostoperator>> expressionPostoperators;
};

using OptionalTypeAndInitListType = boost::tuple<boost::optional<boost::recursive_wrapper<Type>>, boost::recursive_wrapper<Initlist>>;
//using VectorExprpreopExprvalueVectorExprpreopType = boost::tuple<
//        std::vector<Expressionpreoperator>,
//        Expressionvalue,
//        std::vector<boost::recursive_wrapper<Expressionpostoperator>>
//>;

using ExpressiontermType = boost::variant<
    monostate,
    OptionalTypeAndInitListType,
    ExprpreopsExprvalueExprpostops
>;

// EXPRTERM      ::= ([TYPE '='] INITLIST) | ({EXPRPREOP} EXPRVALUE {EXPRPOSTOP})
struct Expressionterm : LocationInfo
{
    Expressionterm() = default;
    
    Expressionterm(ExpressiontermType value) : value(std::move(value))
    {}
    
    ExpressiontermType value;
};

}}

#include "type/Type.hpp"
#include "asg/Initlist.hpp"
#include "asg/Expressionpostoperator.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP