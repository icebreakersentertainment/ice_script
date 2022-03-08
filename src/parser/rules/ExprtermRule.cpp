#include "parser/rules/ExprtermRule.hpp"
#include "parser/rules/TypeRule.hpp"
#include "parser/rules/InitlistRule.hpp"
#include "parser/rules/ExprpreopRule.hpp"
#include "parser/rules/ExprvalueRule.hpp"
#include "parser/rules/ExprpostopRule.hpp"

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

static ExprpreopRuleType _exprpreopRule = exprpreopRule.alias();
static ExprpostopRuleType _exprpostopRule = exprpostopRule.alias();

// EXPRTERM      ::= ([TYPE '='] INITLIST) | ({EXPRPREOP} EXPRVALUE {EXPRPOSTOP})
ExprtermRuleType exprtermRule = qi::eps >> (
            as<ast::OptionalTypeAndInitListType>()[(-(typeRule.alias() >> lit("=")) >> initlistRule.alias())]
            |
            as<ast::VectorExprpreopExprvalueVectorExprpreopType>()[(*_exprpreopRule >> exprvalueRule.alias() >> *_exprpostopRule)]
        );

}}}