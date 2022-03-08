#include "parser/rules/EnumRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/ExprRule.hpp"

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

EnumRuleType
    // ENUM          ::= {'shared' | 'external'} 'enum' IDENTIFIER (';' | ('{' IDENTIFIER ['=' EXPR] {',' IDENTIFIER ['=' EXPR]} '}'))
    enumRule = qi::eps >> *(string("shared") | string("external"))
            >> lit("enum") >> identifierRule.alias()
            >> (
                    lit(";")
                    |
                    (
                            lit("{") >> (identifierRule.alias() >> -(lit("=") >> exprRule.alias())) % ',' >> lit("}")
                    )
            );

}}}