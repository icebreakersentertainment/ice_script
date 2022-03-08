#ifndef ICE_SCRIPT_ASG_EXPRESSIONVALUE_HPP
#define ICE_SCRIPT_ASG_EXPRESSIONVALUE_HPP

#include <string>

#include "ast/Void.hpp"

namespace ice_script { namespace asg {

struct Constructcall;
struct Functioncall;
struct Variableaccess;
struct Cast;
struct Literal;
struct Assign;
struct Lambda;

// EXPRVALUE     ::= 'void' | CONSTRUCTCALL | FUNCCALL | VARACCESS | CAST | LITERAL | '(' ASSIGN ')' | LAMBDA
struct Expressionvalue
{
    boost::variant<
            ast::Void,
            boost::recursive_wrapper<Constructcall>,
            boost::recursive_wrapper<Functioncall>,
            boost::recursive_wrapper<Variableaccess>,
            boost::recursive_wrapper<Cast>,
            boost::recursive_wrapper<Literal>,
            boost::recursive_wrapper<Assign>,
            boost::recursive_wrapper<Lambda>
    > value;
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