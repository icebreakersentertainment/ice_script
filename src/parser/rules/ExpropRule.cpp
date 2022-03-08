#include "parser/rules/ExpropRule.hpp"
#include "parser/rules/MathopRule.hpp"
#include "parser/rules/CompopRule.hpp"
#include "parser/rules/LogicopRule.hpp"
#include "parser/rules/BitopRule.hpp"

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

CompopRuleType _compopRule = compopRule.alias();
BitopRuleType _bitopRule = bitopRule.alias();

ExpropRuleType
    // EXPROP        ::= MATHOP | COMPOP | LOGICOP | BITOP
    expropRule = qi::eps >> (mathopRule.alias() | _compopRule | logicopRule.alias() | _bitopRule);

}}}