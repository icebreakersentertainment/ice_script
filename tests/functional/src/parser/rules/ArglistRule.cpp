#define BOOST_TEST_MODULE ArglistRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include <boost/fusion/adapted/std_tuple.hpp>

#include "parser/rules/ArglistRule.hpp"
#include "parser/TestParser.hpp"

#include "ast/AstPrinter.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    TestParser<ArglistRuleType, ArglistNode> parser{ice_script::parser::rules::arglistRule};
};

BOOST_FIXTURE_TEST_SUITE(ArglistRule, Fixture)

static const std::vector<std::string> parseData = {
        "()",
        "(0)",
        "(0, 1.0)",
        "(0, 1.0, \"test\")",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    parser.parse(sample);
}

static const std::vector<std::string> parseExceptionData = {
        "",
        "(",
        ")",
        "(0,)",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
