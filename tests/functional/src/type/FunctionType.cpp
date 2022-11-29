#define BOOST_TEST_MODULE FunctionType
#include <boost/test/unit_test.hpp>
#include <boost/test/data/test_case.hpp>

#include "type/FunctionType.hpp"

using namespace ice_script;

BOOST_AUTO_TEST_SUITE(FunctionType)

static const std::vector<std::tuple<std::string, std::string, std::vector<std::string>, std::string>> toFunctionTypeKeyTestData = {
        {"v_void", "", {}, "v_void_function_"},
        {"v_void", "", {"v_int"}, "v_void_function_v_int"},
        {"v_int", "", {"v_int", "v_int"}, "v_int_function_v_int_v_int"},
        {"v_int", "v_Test", {"v_int", "v_int"}, "v_int_function_v_Test_v_int_v_int"},
};

BOOST_DATA_TEST_CASE(toFunctionTypeKeyTest, toFunctionTypeKeyTestData, returnTypeKey, classTypeKey, parameterTypeKeys, expected)
{
    const auto functionTypeKey = toFunctionTypeKey(returnTypeKey, classTypeKey, parameterTypeKeys);
 
	BOOST_CHECK_EQUAL(functionTypeKey, expected);
}

BOOST_AUTO_TEST_SUITE_END()
