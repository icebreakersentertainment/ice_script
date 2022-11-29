#include "parser/rules/ParamlistRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/TypemodRule.hpp"
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

static TypeRuleType _typeRule = typeRule.alias();
static TypemodRuleType _typemodRule = typemodRule.alias();
static IdentifierRuleType _identifierRule = identifierRule.alias();
static ExprRuleType _exprRule = exprRule.alias();

// PARAMLIST     ::= '(' ['void' | (TYPE TYPEMOD [IDENTIFIER] ['=' EXPR] {',' TYPE TYPEMOD [IDENTIFIER] ['=' EXPR]})] ')'
//    paramlistRule = qi::eps >> lit("(") >>
//            -qi::as<ast::ParamlistVariantType>()[(
////            (
//                    string("void")
//                    |
//                    (
//                            qi::as<ast::TypeTypeModIdentifierExprType>()[typeRule.alias() >> _typemodRule >> -_identifierRule >> -(lit("=") >> _exprRule)]
//                            >> qi::as<ast::TypeTypeModIdentifierExprType>()[(typeRule.alias() >> _typemodRule >> -_identifierRule >> -(lit("=") >> _exprRule))] % ','
//                    )
//            )]
//            >> lit(")");

ParamlistRuleType paramlistRule = qi::eps >> lit("(") >> -((_typeRule /*>> _typemodRule*/ >> -_identifierRule >> -(lit("=") >> _exprRule)) % ',') >> lit(")");

}}}