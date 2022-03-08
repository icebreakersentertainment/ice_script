#ifndef ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP

#include <string>

#include "asg/Identifier.hpp"
#include "asg/Variable.hpp"
#include "asg/Assign.hpp"
#include "asg/Arglist.hpp"

namespace ice_script { namespace asg {

struct Functioncall;

using VariantFunctioncallVariableType = boost::variant<
        boost::recursive_wrapper<Functioncall>,
        Variable
>;

// EXPRPOSTOP    ::= ('.' (FUNCCALL | IDENTIFIER)) | ('[' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':' ASSIGN} ']') | ARGLIST | '++' | '--'
struct Expressionpostoperator
{
    boost::variant<
            VariantFunctioncallVariableType//,
//            Arglist,
    > value;
//    std::string value;
};

}}

#include "asg/Functioncall.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSIONPOSTOPERATOR_HPP