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

using ReservedKeywordRuleType = boost::spirit::qi::rule<PositionIteratorType, std::string(), SkipperType>;

ReservedKeywordRuleType reservedKeywordRule = lit("return");

// IDENTIFIER    ::= single token:  starts with letter or _, can include any letter and digit, same as in C++
IdentifierRuleType identifierRule = qi::eps >> !reservedKeywordRule >> lexeme[(char_("_") | char_("a-zA-z")) >> *(char_("_") | char_("a-zA-Z0-9"))];

}}}