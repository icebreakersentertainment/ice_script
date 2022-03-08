#include "parser/rules/VarRule.hpp"
#include "parser/rules/VisibilityRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/IdentifierRule.hpp"
#include "parser/rules/InitlistRule.hpp"
#include "parser/rules/ExprRule.hpp"
#include "parser/rules/ArglistRule.hpp"

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

static ExprRuleType _exprRule = exprRule.alias();

static boost::spirit::qi::rule<PositionIteratorType, ast::InitListOrExprOrArgListType(), SkipperType> initListOrExprOrArgList = (lit("=") >> (initlistRule.alias() | _exprRule)) | arglistRule.alias();

// VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
//    varRule = qi::eps >>
//            -(string("private") | string("protected"))
//            >> typeRule.alias() >> identifierRule.alias()
////            >> -(( lit("=") >> (initlistRule.alias() | _exprRule)) | arglistRule.alias())
//            >> initListOrExprOrArgList
//            >> *(
////                    lit(",") >> identifierRule.alias() >> -(( lit("=") >> (initlistRule.alias() | _exprRule)) | arglistRule.alias())
//                    lit(",") >> identifierRule.alias() >> initListOrExprOrArgList
//            )
//            >> lit(";");

VarRuleType varRule = -visibilitySymbols
            >> typeRule.alias()
//            >> -(( lit("=") >> (initlistRule.alias() | _exprRule)) | arglistRule.alias())
            >> identifierRule.alias() >> -initListOrExprOrArgList
            >> -(
//                    lit(",") >> identifierRule.alias() >> -(( lit("=") >> (initlistRule.alias() | _exprRule)) | arglistRule.alias())
                    (identifierRule.alias() >> -initListOrExprOrArgList) % ','
            )
            >> lit(";");

}}}