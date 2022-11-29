#include "parser/rules/ExprvalueRule.hpp"
#include "parser/rules/VoidRule.hpp"
#include "parser/rules/ConstructcallRule.hpp"
#include "parser/rules/FunccallRule.hpp"
#include "parser/rules/VaraccessRule.hpp"
#include "parser/rules/CastRule.hpp"
#include "parser/rules/LiteralRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/LambdaRule.hpp"

namespace ice_script { namespace parser { namespace rules {

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
using namespace boost::spirit;
using namespace boost::spirit::qi;
using qi::int_;
using qi::lit;
using qi::double_;
using qi::lexeme;
using ascii::char_;
using ascii::space;
using ascii::space_type;

//ConstructcallRuleType _constructcallRule = constructcallRule.alias();
FunccallRuleType _funccallRule = funccallRule.alias();

// EXPRVALUE     ::= 'void' | CONSTRUCTCALL | FUNCCALL | VARACCESS | CAST | LITERAL | '(' ASSIGN ')' | LAMBDA
ExprvalueRuleType exprvalueRule = qi::eps >> (voidRule.alias() | _funccallRule | constructcallRule.alias() | varaccessRule.alias() | castRule.alias() | literalRule.alias() | (lit("(") >> assignRule.alias() >> lit(")")) | lambdaRule.alias());

}}}