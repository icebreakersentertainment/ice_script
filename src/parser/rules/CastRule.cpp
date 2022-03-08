#include "parser/rules/CastRule.hpp"
#include "parser/rules/TypeRule.hpp"
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

CastRuleType
    // CAST          ::= 'cast' '<' TYPE '>' '(' ASSIGN ')'
    castRule = qi::eps >> lit("cast") >> lit("<") >> typeRule.alias() >> lit(">") >> lit("(") >> assignRule.alias() >> lit(")");

}}}