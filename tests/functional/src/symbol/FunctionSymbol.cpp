#define BOOST_TEST_MODULE FunctionSymbol
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "symbol/FunctionSymbol.hpp"

using namespace ice_script;

BOOST_AUTO_TEST_SUITE(FunctionSymbol)

static const std::vector<std::tuple<std::string, std::string, std::string, std::vector<std::string>, std::string>> toFunctionSymbolKeyTestData = {
        {"", "", "test", {}, "function_::test"},
        {"::", "", "test", {}, "function_::test"},
        {"::", "Test", "test", {}, "function_::Test::test"},
        {"::", "Test", "test", {"v_int"}, "function_::Test::test_v_int"},
        {"::", "Test", "test", {"v_int", "v_int"}, "function_::Test::test_v_int_v_int"},
        {"::test", "Test", "test", {"v_int", "v_int"}, "function_::test::Test::test_v_int_v_int"},
};

BOOST_DATA_TEST_CASE(toFunctionSymbolKeyTest, toFunctionSymbolKeyTestData, fullyQualifiedScopeName, className, functionName, parameterTypeKeys, expected)
{
    const auto functionSymbolKey = toFunctionSymbolKey(fullyQualifiedScopeName, className, functionName, parameterTypeKeys);
 
	BOOST_CHECK_EQUAL(functionSymbolKey, expected);
}

BOOST_AUTO_TEST_SUITE_END()
