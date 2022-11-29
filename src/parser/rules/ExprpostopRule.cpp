#include "parser/rules/ExprpostopRule.hpp"
#include "parser/rules/FunccallRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/ArglistRule.hpp"
#include "parser/rules/PostfixOperatorRule.hpp"

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

static IdentifierRuleType _identifierRule = identifierRule.alias();

// EXPRPOSTOP    ::= ('.' (FUNCCALL | IDENTIFIER)) | ('[' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':' ASSIGN} ']') | ARGLIST | '++' | '--'
ExprpostopRuleType exprpostopRule = qi::eps >> (
                as<ast::FunccallOrIdentifierType>()[(lit(".") >> (funccallRule.alias() | _identifierRule))]
                // | as<ast::OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType>()[(lit("[") >> -(_identifierRule >> lit(":")) >> assignRule.alias() >> *(lit(",") >> -(_identifierRule >> lit(":")) >> assignRule.alias()) >> lit("]"))]
                | (lit("[") >> assignRule.alias() >> lit("]"))
                | arglistRule.alias()
                | postfixOperatorRule
        );

}}}