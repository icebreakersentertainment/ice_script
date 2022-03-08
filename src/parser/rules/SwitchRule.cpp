#include "parser/rules/SwitchRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/CaseRule.hpp"

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

static CaseRuleType _caseRule = caseRule.alias();

SwitchRuleType
    // SWITCH        ::= 'switch' '(' ASSIGN ')' '{' {CASE} '}'
    switchRule = qi::eps >> lit("switch") >> lit("(") >> assignRule.alias() >> lit(")") >> lit("{") >> *_caseRule >> lit("}");

}}}