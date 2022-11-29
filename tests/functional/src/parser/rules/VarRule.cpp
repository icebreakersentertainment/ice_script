#define BOOST_TEST_MODULE VarRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/VarRule.hpp"
#include "parser/TestParser.hpp"

#include "ast/AstPrinter.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    TestParser<VarRuleType, VarNode> parser{ice_script::parser::rules::varRule};
};

BOOST_FIXTURE_TEST_SUITE(VarRule, Fixture)

// VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
static const std::vector<std::string> parseData = {
       "int id;",
       "int& id;",
       "const int& id;",
       "private int id;",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
   auto root = parser.parse(sample);

   AstPrinter printer{std::cout, true};
   printer(root);
}

static const std::vector<std::string> parseExceptionData = {
        "int id",
//        "privat int id",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
