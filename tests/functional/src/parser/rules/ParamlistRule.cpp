#define BOOST_TEST_MODULE ParamlistRule
#include <boost/test/unit_test.hpp>

#include "parser/rules/ParamlistRule.hpp"
#include "parser/TestParser.hpp"
#include "ast/AstPrinter.hpp"

using namespace ice_script;
using namespace ice_script::parser;
using namespace ice_script::parser::rules;
using namespace ice_script::ast;

BOOST_AUTO_TEST_SUITE(ParamlistRule)

BOOST_AUTO_TEST_CASE(parse)
{
    // PARAMLIST     ::= '(' ['void' | (TYPE TYPEMOD [IDENTIFIER] ['=' EXPR] {',' TYPE TYPEMOD [IDENTIFIER] ['=' EXPR]})] ')'
    const std::vector<std::string> inputs = {
            "()",
            "(void)",
            "(int)",
            "(int&)",
            "(const int&)",
            "(const int& in)",
            "(const int& in a)",
            "(const int& in a = 0)",
    };

    TestParser<ParamlistRuleType, ParamlistNode> parser{ice_script::parser::rules::paramlistRule};

    for (const auto& input : inputs)
    {
        ParamlistNode root = parser.parse(input);

//        AstPrinter printer{std::cout, true};
//        printer(root);
    }
}

BOOST_AUTO_TEST_SUITE_END()