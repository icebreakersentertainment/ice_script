#ifndef ICE_SCRIPT_ASG_FOR_HPP
#define ICE_SCRIPT_ASG_FOR_HPP

#include <string>

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

struct Variable;
struct Expressionstat;
struct Assign;
struct Statement;

// FOR           ::= 'for' '(' (VAR | EXPRSTAT) EXPRSTAT [ASSIGN {',' ASSIGN}] ')' STATEMENT
struct For
{
    boost::variant<monostate, boost::recursive_wrapper<Variable>, boost::recursive_wrapper<Expressionstat>>  variableOrExpressionstat;
    boost::recursive_wrapper<Expressionstat> expressionstat;
    std::vector<boost::recursive_wrapper<Assign>> assigns;
    boost::recursive_wrapper<Statement> statement;
//    std::string value;
};

}}

#include "asg/Variable.hpp"
#include "asg/Expressionstat.hpp"
#include "asg/Assign.hpp"
#include "asg/Statement.hpp"

#endif //ICE_SCRIPT_ASG_FOR_HPP