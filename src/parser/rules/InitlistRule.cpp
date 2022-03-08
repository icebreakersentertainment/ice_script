#include "parser/rules/InitlistRule.hpp"
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

// INITLIST      ::= '{' [ASSIGN | INITLIST] {',' [ASSIGN | INITLIST]} '}'
//    initlistRule = qi::eps >> lit("{") >> -(assignRule.alias() | initlistRule) >> *(lit(",") >> -(assignRule.alias() | initlistRule)) >> lit("}");
InitlistRuleType initlistRule = qi::eps >> lit("{") >> (assignRule.alias() | initlistRule) % ',' >> lit("}");

}}}