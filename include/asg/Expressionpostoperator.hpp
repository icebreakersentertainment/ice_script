#ifndef ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Variable.hpp"
#include "asg/Variableaccess.hpp"
#include "asg/Assign.hpp"
#include "asg/Arglist.hpp"
#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

struct Functioncall;

using VariantFunctioncallVariableType = boost::variant<
        monostate,
        boost::recursive_wrapper<Functioncall>,
        Variable,
        Variableaccess
>;

// EXPRPOSTOP    ::= ('.' (FUNCCALL | IDENTIFIER)) | ('[' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':' ASSIGN} ']') | ARGLIST | '++' | '--'
struct Expressionpostoperator : LocationInfo
{
    Expressionpostoperator() = default;
    
    Expressionpostoperator(VariantFunctioncallVariableType value) : value(std::move(value))
    {}
//    boost::variant<
//            VariantFunctioncallVariableType//,
////            Arglist,
//    > value;
    VariantFunctioncallVariableType value;
//    std::string value;
};

}}

#include "asg/Functioncall.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP