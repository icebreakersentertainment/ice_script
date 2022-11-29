#define BOOST_TEST_MODULE IceScriptEngine
#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>

#include "IceScriptEngine.hpp"

#include "fs/FileSystem.hpp"
#include "logger/Logger.hpp"

#include "exceptions/FileNotFoundException.hpp"

using namespace ice_script;
using namespace ice_script::fs;
using namespace ice_script::logger;
// using namespace ice_script::parser;
// using namespace ice_script::analyzer;
// using namespace ice_script::generator::llvm;
// using namespace ice_script::ast;
// using namespace ice_script::asg;

struct Fixture
{
	Fixture() : logger(), iceScriptEngine(logger, fileSystem)
	{
		fileSystem = ice_script::fs::FileSystem({boost::filesystem::current_path().string(), (boost::filesystem::current_path() / "..").string()});
        std::cout << "HIMOM: " << boost::filesystem::current_path().string() << std::endl;
        std::cout << "HIMOM: " << (boost::filesystem::current_path() / "..").string() << std::endl;

//		const auto mountedFile = boost::filesystem::current_path() / boost::filesystem::path("fixtures/mounted_file.txt");
//		fileSystem.mountFile(mountedFile.string(), "mounted_file.txt");
	}

	FileSystem fileSystem;
    Logger logger;
	IceScriptEngine iceScriptEngine;
};

BOOST_FIXTURE_TEST_SUITE(IceScriptEngine, Fixture)

BOOST_AUTO_TEST_CASE(simpleTest)
{
	const auto contents = fileSystem.readAll("fixtures/test.is");

    iceScriptEngine.execute(contents);

//	BOOST_CHECK_EQUAL(exists, false);
}

BOOST_AUTO_TEST_SUITE_END()
