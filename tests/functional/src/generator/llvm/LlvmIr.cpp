#define BOOST_TEST_MODULE LlvmIr
#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>

#include "parser/Parser.hpp"
#include "analyzer/Analyzer.hpp"
#include "generator/llvm/LlvmIr.hpp"

#include "ast/AstPrinter.hpp"

#include "fs/FileSystem.hpp"
#include "logger/Logger.hpp"

#include "exceptions/FileNotFoundException.hpp"

using namespace ice_script;
using namespace ice_script::fs;
using namespace ice_script::logger;
using namespace ice_script::parser;
using namespace ice_script::analyzer;
using namespace ice_script::generator::llvm;
using namespace ice_script::ast;
using namespace ice_script::asg;

struct Fixture
{
	Fixture() : logger(), parser(logger), analyzer(logger), generator(logger)
	{
		fileSystem = ice_script::fs::FileSystem({boost::filesystem::current_path().string(), (boost::filesystem::current_path() / "..").string()});
        std::cout << "HIMOM: " << boost::filesystem::current_path().string() << std::endl;
        std::cout << "HIMOM: " << (boost::filesystem::current_path() / "..").string() << std::endl;

//		const auto mountedFile = boost::filesystem::current_path() / boost::filesystem::path("fixtures/mounted_file.txt");
//		fileSystem.mountFile(mountedFile.string(), "mounted_file.txt");
	}

	FileSystem fileSystem;
    Logger logger;
    Parser parser;
    Analyzer analyzer;
	LlvmIr generator;
};

BOOST_FIXTURE_TEST_SUITE(LlvmIr, Fixture)

BOOST_AUTO_TEST_CASE(constructor)
{
}

BOOST_AUTO_TEST_CASE(generatorTest)
{
	const auto contents = fileSystem.readAll("fixtures/generator/test.is");

    SymbolTable symbolTable{};
    TypeTable typeTable{};

    const Ast ast = parser.parse(contents);

    AstPrinter printer{std::cout, true};
    printer(ast);

    const Asg asg = analyzer.parse(typeTable, symbolTable, ast);
    const std::string output = generator.generate(typeTable, symbolTable, asg);

    std::cout << "output: " << std::endl;
    std::cout << output << std::endl;

    auto file = fileSystem.open("test.ll", FileFlags::WRITE);
    file->write(output);

//	BOOST_CHECK_EQUAL(exists, false);
}

BOOST_AUTO_TEST_SUITE_END()
