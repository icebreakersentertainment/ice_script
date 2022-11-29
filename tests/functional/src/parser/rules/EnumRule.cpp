#define BOOST_TEST_MODULE EnumRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/EnumRule.hpp"
#include "parser/TestParser.hpp"
#include "ast/AstPrinter.hpp"

#include "detail/Format.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::enumRule)
    {

    }

    TestParser<EnumRuleType, EnumNode> parser;
};

//BOOST_AUTO_TEST_SUITE(EnumRule)
BOOST_FIXTURE_TEST_SUITE(EnumRule, Fixture)

static const std::vector<std::string> parseData = {
        "shared enum ID;",
        "shared enum ID2;",
        R"(shared enum ID3
        {
            E1,
            E2 = 45,
            E3
        })"
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    EnumNode root = parser.parse(sample);

//    AstPrinter printer{std::cout, true};
//    printer(root);
}

static const std::vector<std::string> parseExceptionData = {
        "shared enum ID",
        "shared enum",
        "shared",
        R"(shared enum ID3
        {
            E1,
            E2 = 45,
            E3
        )",
        R"(shared enum ID3
        {
        )",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
