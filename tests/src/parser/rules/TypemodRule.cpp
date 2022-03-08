#define BOOST_TEST_MODULE TypemodRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/TypemodRule.hpp"
#include "parser/TestParser.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::typemodRule)
    {

    }

    TestParser<TypemodRuleType, TypemodNode> parser;
};

//BOOST_AUTO_TEST_SUITE(TypemodRule)
BOOST_FIXTURE_TEST_SUITE(TypemodRule, Fixture)

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
