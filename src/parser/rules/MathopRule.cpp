#include "parser/rules/MathopRule.hpp"
#include "parser/rules/MathOperatorRule.hpp"

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

// MATHOP        ::= '+' | '-' | '*' | '/' | '' | '**'
////        mathopRule = qi::eps >> (string("+") | string("-") | string("*") | string("/") | string("") | string("**"));
MathopRuleType mathopRule = qi::eps >> mathOperatorRule;

}}}