#define BOOST_TEST_MODULE AssignRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/AssignRule.hpp"
#include "parser/TestParser.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::assignRule)
    {

    }

    TestParser<AssignRuleType, AssignNode> parser;
};

//BOOST_AUTO_TEST_SUITE(AssignRule)
BOOST_FIXTURE_TEST_SUITE(AssignRule, Fixture)

// ASSIGN        ::= CONDITION [ ASSIGNOP ASSIGN ]
static const std::vector<std::string> parseData = {
        "a = 1",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    parser.parse(sample);
}

static const std::vector<std::string> parseExceptionData = {
        "a = ",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
