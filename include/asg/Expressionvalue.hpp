#ifndef ICE_SCRIPT_ASG_EXPRESSIONVALUE_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONVALUE_HPP

#include <string>

#include "ast/Void.hpp"
#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

struct Constructcall;
struct Functioncall;
struct Variableaccess;
struct Cast;
struct Literal;
struct Assign;
struct Lambda;

using ExpressionValueType = boost::variant<
        monostate,
        ast::Void,
        boost::recursive_wrapper<Constructcall>,
        boost::recursive_wrapper<Functioncall>,
        boost::recursive_wrapper<Variableaccess>,
        boost::recursive_wrapper<Cast>,
        boost::recursive_wrapper<Literal>,
        boost::recursive_wrapper<Assign>,
        boost::recursive_wrapper<Lambda>
>;

// EXPRVALUE     ::= 'void' | CONSTRUCTCALL | FUNCCALL | VARACCESS | CAST | LITERAL | '(' ASSIGN ')' | LAMBDA
struct Expressionvalue : LocationInfo
{
    Expressionvalue() = default;
    
    Expressionvalue(ExpressionValueType value) : value(std::move(value))
    {}
    
    
    ExpressionValueType value;
};

}}

#include "asg/Constructcall.hpp"
#include "asg/Functioncall.hpp"
#include "asg/Variableaccess.hpp"
#include "asg/Cast.hpp"
#include "asg/Literal.hpp"
#include "asg/Assign.hpp"
#include "asg/Lambda.hpp"

#endif //ICE_SCRIPT_ASG_EXPRESSIONVALUE_HPP