#include "IceScriptEngine.hpp"

#include "engine/llvm/LlvmOrcJit.hpp"

#include "parser/Parser.hpp"
#include "analyzer/Analyzer.hpp"
#include "generator/llvm/LlvmIr.hpp"

#include "ast/AstPrinter.hpp"

namespace ice_script
{

using namespace ice_script::parser;
using namespace ice_script::analyzer;
using namespace ice_script::generator::llvm;
using namespace ice_script::ast;
using namespace ice_script::asg;
using namespace ice_script::engine::llvm;

void IceScriptEngine::execute(const std::string& script)
{
//        const auto contents = fileSystem_->readAll("fixtures/generator/test.is");
        Parser parser{*logger_};
        Analyzer analyzer{*logger_};
        LlvmIr generator{*logger_};
        // Parser parser{*context_.logger()};
        // Analyzer analyzer{*context_.logger()};
        // LlvmIr generator{*context_.logger()};

        SymbolTable symbolTable{};
        TypeTable typeTable{};

        const Ast ast = parser.parse(script);

        AstPrinter printer{std::cout, true};
        printer(ast);

        const Asg asg = analyzer.parse(typeTable, symbolTable, ast);
        const std::string output = generator.generate(typeTable, symbolTable, asg);

        std::cout << "output: " << std::endl;
        std::cout << output << std::endl;

        LlvmOrcJit jit{*logger_, *fileSystem_};
        // LlvmOrcJit jit{*context_.logger(), *context_.fileSystem()};

        jit.execute(output);

//        auto file = fileSystem_->open("test.ll", FileFlags::WRITE);
//        file->write(output);
    }
}