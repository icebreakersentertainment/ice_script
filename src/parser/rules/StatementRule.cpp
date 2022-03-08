#include "parser/rules/StatementRule.hpp"
#include "parser/rules/IfRule.hpp"
#include "parser/rules/ForRule.hpp"
#include "parser/rules/WhileRule.hpp"
#include "parser/rules/ReturnRule.hpp"
#include "parser/rules/StatblockRule.hpp"
#include "parser/rules/BreakRule.hpp"
#include "parser/rules/ContinueRule.hpp"
#include "parser/rules/DowhileRule.hpp"
#include "parser/rules/SwitchRule.hpp"
#include "parser/rules/ExprstatRule.hpp"
#include "parser/rules/TryRule.hpp"

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

static ForRuleType _forRule = forRule.alias();

    // STATEMENT     ::= (IF | FOR | WHILE | RETURN | STATBLOCK | BREAK | CONTINUE | DOWHILE | SWITCH | EXPRSTAT | TRY)
StatementRuleType statementRule = (ifRule.alias() | _forRule | whileRule.alias() | returnRule.alias() | statblockRule.alias() | breakRule.alias() | continueRule.alias() | dowhileRule.alias() | switchRule.alias() | exprstatRule.alias() | tryRule.alias());

}}}