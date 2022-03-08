#include "parser/rules/FuncdefRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ParamlistRule.hpp"

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

FuncdefRuleType
    // FUNCDEF       ::= {'external' | 'shared'} 'funcdef' TYPE ['&'] IDENTIFIER PARAMLIST ';'
    funcdefRule = qi::eps >> *(string("external") | string("shared")) >> lit("funcdef") >> typeRule.alias() >> -string("&") >> identifierRule.alias() >> paramlistRule.alias() >> lit(";");

}}}