#include "parser/rules/StatblockRule.hpp"
#include "parser/rules/VarRule.hpp"
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

static StatementRuleType _statementRule = statementRule.alias();

// STATBLOCK     ::= '{' {VAR | STATEMENT} '}'
StatblockRuleType statblockRule = qi::eps >> lit("{") >> *(_statementRule | varRule.alias()) >> lit("}");

}}}