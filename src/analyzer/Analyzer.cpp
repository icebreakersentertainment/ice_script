#include "analyzer/Analyzer.hpp"

#include "analyzer/detail/AnalyzerVisitor.hpp"
#include "analyzer/detail/TypeTablePassVisitor.hpp"
#include "analyzer/detail/SymbolTablePassVisitor.hpp"

#include "analyzer/detail/TypeTableUtilities.hpp"

//#include "detail/Format.hpp"

namespace ice_script { namespace analyzer {

using namespace ice_script::ast;
using namespace ice_script::asg;
using namespace ice_script::analyzer::detail;

asg::Asg Analyzer::parse(TypeTable& typeTable, SymbolTable& symbolTable, const ast::Ast& ast)
{
    LOG_DEBUG(logger_, "Parsing ast");
    
    using namespace boost::spirit::qi;
    using boost::spirit::ascii::space;

    Asg asg;

    populate(typeTable);

    TypeTablePassVisitor typeTablePassVisitor{*logger_, typeTable, symbolTable};

    for (const auto& value : ast.root.scriptNode.value)
    {
        boost::apply_visitor(typeTablePassVisitor, value);
    }

    // std::cout << toString(typeTable) << std::endl;

    SymbolTablePassVisitor symbolTablePassVisitor{*logger_, typeTable, symbolTable};

    for (const auto& value : ast.root.scriptNode.value)
    {
        boost::apply_visitor(symbolTablePassVisitor, value);
    }

    // std::cout << toString(symbolTable) << std::endl;

    Context context{*logger_};
    Scope scope{};
//    SymbolTable symbolTable{};

//    TypeTable& typeTable = context.typeTable();

//    populate(typeTable);

    context.setTypeTable(typeTable);
    context.setSymbolTable(symbolTable);

    AnalyzerVisitor analyzerVisitor{context, scope, symbolTable};

//    std::cout << context << std::endl;

    for (const auto& value : ast.root.scriptNode.value)
    {
        asg.root.nodes.push_back(boost::apply_visitor(analyzerVisitor, value));
    }

    return asg;
}

}}