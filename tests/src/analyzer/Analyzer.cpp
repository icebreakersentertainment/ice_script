#define BOOST_TEST_MODULE Analyzer
#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>

#include "fs/FileSystem.hpp"

#include "parser/Parser.hpp"
#include "analyzer/Analyzer.hpp"
#include "ast/AstPrinter.hpp"

#include "exceptions/FileNotFoundException.hpp"

using namespace ice_script::fs;
using namespace ice_script::parser;
using namespace ice_script::analyzer;
using namespace ice_script::ast;
using namespace ice_script::asg;

struct Fixture
{
	Fixture()
	{
		fileSystem = ice_script::fs::FileSystem({boost::filesystem::current_path().string(), (boost::filesystem::current_path() / "..").string()});
        std::cout << "HIMOM: " << boost::filesystem::current_path().string() << std::endl;
        std::cout << "HIMOM: " << (boost::filesystem::current_path() / "..").string() << std::endl;
        parser = Parser();
        analyzer = Analyzer();
//		const auto mountedFile = boost::filesystem::current_path() / boost::filesystem::path("fixtures/mounted_file.txt");
//		fileSystem.mountFile(mountedFile.string(), "mounted_file.txt");
	}
	
	FileSystem fileSystem;
	Parser parser;
	Analyzer analyzer;
};

BOOST_FIXTURE_TEST_SUITE(Analyzer, Fixture)

BOOST_AUTO_TEST_CASE(constructor)
{
}

BOOST_AUTO_TEST_CASE(parseTest)
{
	const auto contents = fileSystem.readAll("fixtures/analyzer/test.is");

    const Ast ast = parser.parse(contents);
    const Asg asg = analyzer.parse(ast);

//    std::cout << "ast.root.data: " << ast.root.data << std::endl;
//    std::cout << "ast.root.data: " << ast.root.data2 << std::endl;
//    std::cout << "ast.root.data: " << ast.root. << std::endl;

    std::cout << "asg: " << std::endl;

//    AstPrinter printer{std::cout, true};
//    printer(ast);

//	BOOST_CHECK_EQUAL(exists, false);
}

BOOST_AUTO_TEST_SUITE_END()
