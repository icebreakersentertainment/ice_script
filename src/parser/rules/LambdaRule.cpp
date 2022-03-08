#include "parser/rules/LambdaRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/TypemodRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/StatblockRule.hpp"

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

TypemodRuleType _typemodRule = typemodRule.alias();

LambdaRuleType
    // LAMBDA        ::= 'function' '(' [[TYPE TYPEMOD] IDENTIFIER {',' [TYPE TYPEMOD] IDENTIFIER}] ')' STATBLOCK
    lambdaRule = qi::eps >> lit("function") >> lit("(") >> -(-(typeRule.alias() >> _typemodRule) >> identifierRule.alias() >> *(lit(",") >> -(typeRule.alias() >> _typemodRule) >> identifierRule.alias())) >> lit(")") >> statblockRule.alias();

}}}