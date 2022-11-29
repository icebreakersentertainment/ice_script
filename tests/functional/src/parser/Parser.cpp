#define BOOST_TEST_MODULE Parser
#include <boost/test/unit_test.hpp>

#include <boost/filesystem.hpp>

#include "fs/FileSystem.hpp"

#include "parser/Parser.hpp"
//#include "parser/Parser2.hpp"
#include "ast/AstPrinter.hpp"
//#include "parser/AstPrinter2.hpp"

#include "parser/rules/NumberRule.hpp"

#include "exceptions/FileNotFoundException.hpp"

using namespace ice_script::fs;
using namespace ice_script::parser;
using namespace ice_script::ast;

struct Fixture
{
	Fixture()
	{
		fileSystem = ice_script::fs::FileSystem({boost::filesystem::current_path().string(), (boost::filesystem::current_path() / "..").string()});
        std::cout << "HIMOM: " << boost::filesystem::current_path().string() << std::endl;
        std::cout << "HIMOM: " << (boost::filesystem::current_path() / "..").string() << std::endl;
        parser = Parser();
//		const auto mountedFile = boost::filesystem::current_path() / boost::filesystem::path("fixtures/mounted_file.txt");
//		fileSystem.mountFile(mountedFile.string(), "mounted_file.txt");
	}
	
	FileSystem fileSystem;
	Parser parser;
};

BOOST_FIXTURE_TEST_SUITE(Parser, Fixture)

BOOST_AUTO_TEST_CASE(constructor)
{
}

BOOST_AUTO_TEST_CASE(parseTest)
{
	const auto contents = fileSystem.readAll("fixtures/parser/test.is");

    const Ast ast = parser.parse(contents);

//    std::cout << "ast.root.data: " << ast.root.data << std::endl;
//    std::cout << "ast.root.data: " << ast.root.data2 << std::endl;
//    std::cout << "ast.root.data: " << ast.root. << std::endl;

    std::cout << "ast: " << std::endl;

    AstPrinter printer{std::cout, true};
    printer(ast);

//	BOOST_CHECK_EQUAL(exists, false);
}

//BOOST_AUTO_TEST_CASE(doesFileExist)
//{
//	const bool exists = fileSystem.exists("fixtures/filesystem_test_file.txt");
//
//	BOOST_CHECK_EQUAL(exists, true);
//}
//
//BOOST_AUTO_TEST_CASE(doesFileExistWithRelativeDirectory)
//{
//	const bool exists = fileSystem.exists("fixtures/../fixtures/filesystem_test_file.txt");
//
//	BOOST_CHECK_EQUAL(exists, true);
//}
//
//BOOST_AUTO_TEST_CASE(fileOutsideOfMountedBaseDirectory)
//{
//    const auto tempDirPath = boost::filesystem::temp_directory_path();
//    const auto tempFile = tempDirPath / boost::filesystem::unique_path();
//
//    AutoDeletingFile adf{tempFile.string()};
//
//    auto relativeTempFile = boost::filesystem::relative(tempFile);
//
//	const bool exists = fileSystem.exists( relativeTempFile.string() );
//
//	BOOST_CHECK_EQUAL(exists, false);
//}
//
//BOOST_AUTO_TEST_CASE(doesFolderExist)
//{
//	const bool exists = fileSystem.exists("fixtures");
//
//	BOOST_CHECK_EQUAL(exists, true);
//}
//
//BOOST_AUTO_TEST_CASE(isNotDirectory)
//{
//	const bool isDirectory = fileSystem.isDirectory("fixtures/filesystem_test_file.txt");
//
//	BOOST_CHECK_EQUAL(isDirectory, false);
//}
//
//BOOST_AUTO_TEST_CASE(isDirectory)
//{
//	const bool isDirectory = fileSystem.isDirectory( "fixtures");
//
//	BOOST_CHECK_EQUAL(isDirectory, true);
//}
//
//BOOST_AUTO_TEST_CASE(deleteFile)
//{
//    const auto tempDirPath = boost::filesystem::temp_directory_path();
//
//    fileSystem.mountBaseDirectory(tempDirPath.string());
//
//    const auto tempFileName = boost::filesystem::unique_path();
//    const auto tempFile = tempDirPath / tempFileName;
//
//    AutoDeletingFile adf{tempFile.string()};
//
//	fileSystem.deleteFile(tempFileName.string());
//
//	const bool exists = fileSystem.exists(tempFile.string());
//
//	BOOST_CHECK_EQUAL(exists, false);
//}
//
//BOOST_AUTO_TEST_CASE(read)
//{
//    auto file = fileSystem.open("fixtures/filesystem_test_file.txt", ice_script::fs::FileFlags::READ);
//
//    const auto content = file->read(256);
//
//    BOOST_CHECK_EQUAL(content, "testing");
//}
//
//BOOST_AUTO_TEST_CASE(readAll)
//{
//    const auto content = fileSystem.readAll("fixtures/filesystem_test_file.txt");
//
//    BOOST_CHECK_EQUAL(content, "testing");
//}
//
//BOOST_AUTO_TEST_CASE(readAllFileDoesNotExist)
//{
//    fileSystem = ice_script::fs::FileSystem();
//
//    BOOST_CHECK_THROW(fileSystem.readAll("fixtures/filesystem_test_file.txt"), ice_script::FileNotFoundException);
//}
//
//BOOST_AUTO_TEST_CASE(readAllMountedFile)
//{
//    const auto content = fileSystem.readAll("mounted_file.txt");
//
//    BOOST_CHECK_EQUAL(content, "testing");
//}

BOOST_AUTO_TEST_SUITE_END()
