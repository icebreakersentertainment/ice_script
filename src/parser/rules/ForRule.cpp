#include "parser/rules/ForRule.hpp"
#include "parser/rules/VarRule.hpp"
#include "parser/rules/ExprstatRule.hpp"
#include "parser/rules/AssignRule.hpp"
#include "parser/rules/StatementRule.hpp"

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

static ExprstatRuleType _exprstatRule = exprstatRule.alias();
static AssignRuleType _assignRule = assignRule.alias();

// FOR           ::= 'for' '(' (VAR | EXPRSTAT) EXPRSTAT [ASSIGN {',' ASSIGN}] ')' STATEMENT
ForRuleType forRule = lit("for") >> lit("(")
            >> (varRule.alias() | _exprstatRule)
            >> _exprstatRule >> _assignRule % ',' >> lit(")") >> statementRule.alias();

}}}