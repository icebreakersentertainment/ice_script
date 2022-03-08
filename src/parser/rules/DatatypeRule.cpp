#include "parser/rules/DatatypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/PrimtypeRule.hpp"

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

PrimtypeRuleType _primtypeRule = primtypeRule.alias();

// DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
//DatatypeRuleType datatypeRule = qi::eps >> (identifierRule.alias() | _primtypeRule | string("?") | string("auto"));
DatatypeRuleType datatypeRule = qi::eps >> (_primtypeRule | identifierRule.alias() | string("?") | string("auto"));

}}}