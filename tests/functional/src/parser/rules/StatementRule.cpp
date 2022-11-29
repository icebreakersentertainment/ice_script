#define BOOST_TEST_MODULE StatementRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/StatementRule.hpp"
#include "parser/TestParser.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::statementRule)
    {

    }

    TestParser<StatementRuleType, StatementNode> parser;
};

//BOOST_AUTO_TEST_SUITE(StatementRule)
BOOST_FIXTURE_TEST_SUITE(StatementRule, Fixture)

// STATEMENT     ::= (IF | FOR | WHILE | RETURN | STATBLOCK | BREAK | CONTINUE | DOWHILE | SWITCH | EXPRSTAT | TRY)
// statementRule = qi::eps >> (ifRule.alias() | _forRule | whileRule.alias() | returnRule.alias() | statblockRule.alias() | breakRule.alias() | continueRule.alias() | dowhileRule.alias() | switchRule.alias() | exprstatRule.alias() | tryRule.alias());
static const std::vector<std::string> parseData = {
        "",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    parser.parse(sample);
}

static const std::vector<std::string> parseExceptionData = {
        "",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
