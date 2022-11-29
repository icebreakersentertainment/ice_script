#include "parser/rules/ArglistRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
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

// ARGLIST       ::= '(' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':'] ASSIGN} ')'
//    arglistRule = qi::eps >> lit("(") >> -(identifierRule.alias() >> string(":")) >> assignRule.alias() >> *(lit(",") >> -(identifierRule.alias() >> string(":")) >> assignRule.alias()) >> lit(")");
ArglistRuleType arglistRule = qi::eps >> lit("(")
            >> as<ast::ArglistArgumentsType>()[-((-(identifierRule.alias() >> lit(":")) >> assignRule.alias()) % ',')]
//            >> -(-(identifierRule.alias() >> string(":")) >> assignRule.alias()) % ','
            >> lit(")");

}}}