#define BOOST_TEST_MODULE IfRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/IfRule.hpp"
#include "parser/TestParser.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::ifRule)
    {

    }

    TestParser<IfRuleType, IfNode> parser;
};

//BOOST_AUTO_TEST_SUITE(IfRule)
BOOST_FIXTURE_TEST_SUITE(IfRule, Fixture)

static const std::vector<std::string> parseData = {
        "if (true) {}",
        "if (true) {} else {}",
        "if (true) {} else if (true) {}",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    parser.parse(sample);
}

static const std::vector<std::string> parseExceptionData = {
        "if (true) {",
        "if (true)",
        "if (true",
        "if (",
        "if",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
