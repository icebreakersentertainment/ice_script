#include "parser/rules/ExprRule.hpp"
#include "parser/rules/ExprtermRule.hpp"
#include "parser/rules/ExpropRule.hpp"

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

static ExpropRuleType _expropRule = expropRule.alias();

// EXPR          ::= EXPRTERM {EXPROP EXPRTERM}
ExprRuleType exprRule = qi::eps >> exprtermRule.alias() >> *(_expropRule >> exprtermRule.alias());

}}}