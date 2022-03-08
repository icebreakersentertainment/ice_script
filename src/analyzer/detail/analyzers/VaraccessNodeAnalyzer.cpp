#include "analyzer/detail/analyzers/VaraccessNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Variableaccess process(logger::ILogger& logger, Context& context, const ast::VaraccessNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Variableaccess variableaccess{};

    variableaccess.name = toName(node.identifierNode.get().value);

//    Symbol* symbol = scope.symbolTable().find(variableName);

//        if (symbol) throw DuplicateSymbolException(symbol);
//    if (symbol) throw DuplicateSymbolException();
//        if (symbol) throw RedeclarationException(symbol);

    return variableaccess;
}

}}}