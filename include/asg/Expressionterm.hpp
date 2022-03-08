#ifndef ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP

#include <string>

#include "asg/Expressionpreoperator.hpp"
#include "asg/Expressionvalue.hpp"

namespace ice_script { namespace asg {

class Type;

struct Initlist;
struct Expressionpostoperator;

using OptionalTypeAndInitListType = boost::tuple<boost::optional<boost::recursive_wrapper<Type>>, boost::recursive_wrapper<Initlist>>;
using VectorExprpreopExprvalueVectorExprpreopType = boost::tuple<
        std::vector<Expressionpreoperator>,
        Expressionvalue,
        std::vector<boost::recursive_wrapper<Expressionpostoperator>>
>;

// EXPRTERM      ::= ([TYPE '='] INITLIST) | ({EXPRPREOP} EXPRVALUE {EXPRPOSTOP})
struct Expressionterm
{
    boost::variant<
            OptionalTypeAndInitListType,
            VectorExprpreopExprvalueVectorExprpreopType
    > value;
};

}}

#include "asg/Type.hpp"
#include "asg/Initlist.hpp"
#include "asg/Expressionpostoperator.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSIONTERM_HPP