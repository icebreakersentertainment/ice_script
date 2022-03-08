#include "parser/rules/LiteralRule.hpp"
#include "parser/rules/NumberRule.hpp"
#include "parser/rules/StringRule.hpp"
#include "parser/rules/BitsRule.hpp"
#include "parser/rules/BoolRule.hpp"
#include "parser/rules/NullRule.hpp"

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

StringRuleType _stringRule = stringRule.alias();

// LITERAL       ::= NUMBER | STRING | BITS | 'true' | 'false' | 'null'
//LiteralRuleType literalRule = qi::eps >> (numberRule.alias() | _stringRule | bitsRule.alias() | string("true") | string("false") | string("null"));
LiteralRuleType literalRule = qi::eps >> (numberRule.alias() | _stringRule | bitsRule.alias() | boolRule.alias() | nullRule.alias());

}}}