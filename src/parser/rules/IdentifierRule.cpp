#include "parser/rules/IdentifierRule.hpp"

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

IdentifierRuleType
    // IDENTIFIER    ::= single token:  starts with letter or _, can include any letter and digit, same as in C++
    identifierRule = qi::eps >> lexeme[(char_("_") | char_("a-zA-z")) >> *(char_("_") | char_("a-zA-Z0-9"))];

}}}