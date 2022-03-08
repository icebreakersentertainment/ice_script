#define BOOST_TEST_MODULE TypeRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/TypeRule.hpp"
#include "parser/TestParser.hpp"
#include "ast/AstPrinter.hpp"

#include "detail/Format.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::typeRule)
    {

    }

    TestParser<TypeRuleType, TypeNode> parser;
};

//BOOST_AUTO_TEST_SUITE(TypeRule)
BOOST_FIXTURE_TEST_SUITE(TypeRule, Fixture)

static const std::vector<std::string> parseData = {
        "void",
        "int",
        "const int",
        "const ::my_scope::int",
        "const ::my_scope::int <const ::my_scope::int>",
        "const ::my_scope::int <const ::my_scope::int>[]",
        "const ::my_scope::int <const ::my_scope::int>@",
        "const ::my_scope::int <const ::my_scope::int>@ const",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    TypeNode root = parser.parse(sample);

//    AstPrinter printer{std::cout, true};
//    printer(root);
}

static const std::vector<std::string> parseExceptionData = {
        "cons int",
        "const :my_scope::int",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
