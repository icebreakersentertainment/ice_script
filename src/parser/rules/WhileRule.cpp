#include "parser/rules/WhileRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/StatementRule.hpp"

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

WhileRuleType
    // WHILE         ::= 'while' '(' ASSIGN ')' STATEMENT
    whileRule = qi::eps >> lit("while") >> lit("(") >> assignRule.alias() >> lit(")") >> statementRule.alias();

}}}