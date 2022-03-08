#include "parser/rules/DowhileRule.hpp"
#include "parser/rules/StatementRule.hpp"
#include "parser/rules/AssignRule.hpp"

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

DowhileRuleType
    // DOWHILE       ::= 'do' STATEMENT 'while' '(' ASSIGN ')' ';'
    dowhileRule = qi::eps >> lit("do") >> statementRule.alias() >> lit("while") >> lit("(") >> assignRule.alias() >> lit(")") >> lit(";");

}}}