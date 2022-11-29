#define BOOST_TEST_MODULE StatblockRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/StatblockRule.hpp"
#include "parser/TestParser.hpp"

#include "ast/AstPrinter.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    TestParser<StatblockRuleType, StatblockNode> parser{ice_script::parser::rules::statblockRule};
};

BOOST_FIXTURE_TEST_SUITE(StatblockRule, Fixture)

static const std::vector<std::string> parseData = {
        "{}",
        "{ int a = 0; }",
        "{ const int a = 0; }",
        "{ int& a = 0; }",
        "{ const int& a = 0; }",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    auto root = parser.parse(sample);
    
    AstPrinter printer{std::cout, true};
    printer(root);
}

static const std::vector<std::string> parseExceptionData = {
        "{",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
