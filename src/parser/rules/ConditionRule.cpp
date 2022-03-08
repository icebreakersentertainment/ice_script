#include "parser/rules/ConditionRule.hpp"
#include "parser/rules/ExprRule.hpp"
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

// CONDITION     ::= EXPR ['?' ASSIGN ':' ASSIGN]
ConditionRuleType conditionRule = qi::eps >> exprRule.alias() >> -(lit("?") >> assignRule.alias() >> lit(":") >> assignRule.alias());

}}}