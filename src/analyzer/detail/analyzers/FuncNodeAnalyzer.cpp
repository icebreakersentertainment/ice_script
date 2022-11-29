#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/TypeKeyResolver.hpp"
#include "analyzer/detail/SymbolKeyResolver.hpp"
#include "analyzer/detail/SetLocationInfo.hpp"
#include <memory>

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

inline std::shared_ptr<Symbol> createSymbol(Context& context, const TypeTypeModIdentifierExpr& typeTypeModIdentifierExpr)
{
    const auto typeKey = resolveTypeKey(context, typeTypeModIdentifierExpr.typeNode.get());
    
    const auto type = context.typeTable().getByKey(typeKey);
    
    const auto name = typeTypeModIdentifierExpr.optionalIdentifierNode.get().get().value;

    if (!context.scope().symbolTable().find(name).empty()) throw DuplicateSymbolException();

    auto symbol = std::make_shared<Symbol>(name);

    symbol->setType(type);
    symbol->setFullyQualifiedScopeName(context.scope().fullyQualifiedName());

    return symbol;
}

Variable toVariable(Context& context, const TypeTypeModIdentifierExpr& typeTypeModIdentifierExpr)
{
    Variable variable{};

    variable.symbol = createSymbol(context, typeTypeModIdentifierExpr);
    // variable.type = resolve(context, typeTypeModIdentifierExpr.typeNode.get());
    variable.name = typeTypeModIdentifierExpr.optionalIdentifierNode.get().get().value;

    if (typeTypeModIdentifierExpr.optionalExprNode)
    {
        variable.value = process(context, typeTypeModIdentifierExpr.optionalExprNode.get().get());
    }

    return variable;
}

asg::Function process(Context& context, const ast::FuncNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    
    Scope& scope = context.scope();
    Scope& currentScope = context.pushScope(name, ScopeType::FUNCTION);

    Function function{};

    setLocationInfo(function, node);

    function.name = name;

    const auto symbolKey = resolveSymbolKey(context, node);
    auto symbol = scope.symbolTable().findFunctionByKey(symbolKey);

    if (!symbol) symbol = context.symbolTable().getFunctionByKey(symbolKey);

    function.symbol = symbol;
    function.returnType = symbol->type()->returnType();

    std::vector<Variable> parameters{};
    for (const auto& parameter : node.paramlistNode.get().value)
    {
        parameters.push_back(toVariable(context, parameter));
    }

    function.parameters = parameters;

    scope.symbolTable().add(symbol);
    currentScope.symbolTable().add(symbol);

    if (symbol->ownerSymbol())
    {
        const auto& classSymbol = scope.symbolTable().getClassByKey(symbol->ownerSymbol()->key());
        
        auto thisSymbol = std::make_shared<ClassSymbol>(*classSymbol);
        
        auto thisType = context.typeTable().find(thisSymbol->type(), thisSymbol->type()->qualifiers() | (symbol->type()->qualifiers() & TypeQualifier::TypeQualifierFlags::CONSTANT), TypeModifier::POINTER);
        
        thisSymbol->setType(thisType);
        thisSymbol->setName("this");
        
        currentScope.symbolTable().add(thisSymbol);
        
        for (const auto& memberVariable : classSymbol->memberVariables())
        {
            if (!currentScope.symbolTable().findByKey(memberVariable->key())) currentScope.symbolTable().add(memberVariable);
        }
        
        for (const auto& constructor : classSymbol->constructors())
        {
            if (!currentScope.symbolTable().findByKey(constructor->key())) currentScope.symbolTable().add(constructor);
        }
        
        for (const auto& function : classSymbol->functions())
        {
            if (!currentScope.symbolTable().findByKey(function->key())) currentScope.symbolTable().add(function);
        }
    }

    for (const auto& parameter : parameters)
    {
        currentScope.symbolTable().add(parameter.symbol);
    }

    context.pushExpectedReturnTypes({function.returnType});

    if (node.optionalStatblockNode)
    {
        const auto& statblockNode = node.optionalStatblockNode.get();

        function.body = process(context, statblockNode.get());
    }

    context.popExpectedReturnTypes();

    context.popScope();

    return function;
}

}}}