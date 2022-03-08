#define BOOST_TEST_MODULE ImportRule
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "parser/rules/ImportRule.hpp"
#include "parser/TestParser.hpp"
#include "ast/AstPrinter.hpp"

#include "detail/Format.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

struct Fixture
{
    Fixture() : parser(ice_script::parser::rules::importRule)
    {

    }

    TestParser<ImportRuleType, ImportNode> parser;
};

//BOOST_AUTO_TEST_SUITE(ImportRule)
BOOST_FIXTURE_TEST_SUITE(ImportRule, Fixture)

static const std::vector<std::string> parseData = {
        "import int id() from \"test\";",
        "import int id(int a, int b) from \"test\";",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse, parseData)
{
    ImportNode root = parser.parse(sample);

//    AstPrinter printer{std::cout, true};
//    printer(root);
}

// IMPORT        ::= 'import' TYPE ['&'] IDENTIFIER PARAMLIST FUNCATTR 'from' STRING ';'
// importRule = qi::eps >> lit("import") >> typeRule.alias() >> -string("&") >> identifierRule.alias() >> paramlistRule.alias() >> funcattrRule.alias() >> lit("from") >> stringRule.alias() >> lit(";");
static const std::vector<std::string> parseExceptionData = {
        "import int id() from \"test\"",
        "import int id() from",
        "import int id()",
        "import int id",
        "import int",
        "import",
};

BOOST_DATA_TEST_CASE_F(Fixture, parse_Exception, parseExceptionData)
{
    BOOST_CHECK_THROW(parser.parse(sample), std::exception);
}

BOOST_AUTO_TEST_SUITE_END()
