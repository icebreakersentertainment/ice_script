#include "analyzer/detail/analyzers/VaraccessNodeAnalyzer.hpp"

#include "type/TypeQualifier.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Variableaccess process(Context& context, const ast::VaraccessNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Variableaccess variableaccess{};

    const auto symbols = scope.symbolTable().find(node.identifierNode.get().value);
    
    if (symbols.empty()) throw SymbolNotFoundException("");
    
    ICE_SCRIPT_ASSERT(symbols.size() == 1);
    
    variableaccess.symbol = symbols.at(0);
    
    if (variableaccess.symbol->ownerSymbol())
    {
        const auto thisSymbols = scope.symbolTable().find("this");
        
        ICE_SCRIPT_ASSERT(thisSymbols.size() == 1);
        
        // variableaccess.thisSymbol = thisSymbols.at(0);
        const auto thisSymbol = thisSymbols.at(0);
        
        if (thisSymbol->type()->qualifiers() & TypeQualifier::TypeQualifierFlags::CONSTANT)
        {
            variableaccess.type = context.typeTable().find(variableaccess.symbol->type(), variableaccess.symbol->type()->qualifiers() | TypeQualifier::TypeQualifierFlags::CONSTANT, variableaccess.symbol->type()->modifier());
        }
        else
        {
            variableaccess.type = variableaccess.symbol->type();
        }
    }
    
    return variableaccess;
}

}}}