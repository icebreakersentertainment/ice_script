#include "analyzer/detail/analyzers/FuncNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/AbstractVisitor.hpp"

#include "analyzer/detail/TypeResolver.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

std::shared_ptr<FunctionType> createFunctionType(logger::ILogger& logger, Context& context, const FuncNode& node)
{
    std::shared_ptr<FunctionType> functionType{};

    if (node.value1)
    {
        if (node.value1.get().type() == typeid(ast::TupleTypeOptionalStringType))
        {
            const auto& tupleTypeOptionalString = boost::get<ast::TupleTypeOptionalStringType>(node.value1.get());
            const auto& typeNode = tupleTypeOptionalString.get<0>();

            std::shared_ptr<Type> type = resolve(logger, context, typeNode.get());

            functionType->setReturnType(type);
        }
    }

    return functionType;
}

class TypeKey
{
public:
    explicit TypeKey(std::string key = "") : value_(std::move(key))
    {}

    const std::string& value() const
    {
        return value_;
    }

private:
    std::string value_;
};

TypeKey toTypeKey(const IdentifierNode& node)
{
    return TypeKey(toName(node.value));
}

TypeKey toTypeKey(const PrimtypeNode& node)
{
    return TypeKey(toString(node.primitiveType));
}

class TypeKeyVisitor : public AbstractVisitor<TypeKeyVisitor, TypeKey>
{
    using AbstractVisitor::AbstractVisitor;

    using AbstractVisitor::operator();

    TypeKey operator()(const IdentifierNode& node) { return toTypeKey(node); }
    TypeKey operator()(const PrimtypeNode& node) { return toTypeKey(node); }
};



TypeKey toTypeKey(const DatatypeNode& node)
{
    TypeKeyVisitor visitor{};
    return boost::apply_visitor(visitor, node.value);
}

TypeKey toTypeKey(const TypeNode& node)
{
    return toTypeKey(node.datatypeNode);
}

TypeKey toTypeKey(const ParamlistNode& node)
{

}

TypeKey toTypeKey(const FuncNode& node)
{
    TypeKey returnTypeKey{};

    if (node.value1)
    {
        if (node.value1.get().type() == typeid(ast::TupleTypeOptionalStringType))
        {
            const auto& tupleTypeOptionalString = boost::get<ast::TupleTypeOptionalStringType>(node.value1.get());
            const auto& typeNode = tupleTypeOptionalString.get<0>();

            returnTypeKey = toTypeKey(typeNode.get());
        }
    }

    const auto name = toName(node.identifierNode.get().value);

    TypeKey paramlistTypeKey = toTypeKey(node.paramlistNode.get());

    return returnTypeKey + TypeKey(name) + paramlistTypeKey;
}

std::shared_ptr<FunctionSymbol> createFunctionSymbol(logger::ILogger& logger, Context& context, const FuncNode& node)
{
    std::shared_ptr<FunctionType> functionType{};

    const auto symbolKey = toSymbolKey(node);

    if (scope.symbolTable().findFunction(symbolKey)) throw DuplicateSymbolException();

    //    const auto name = toName(node.identifierNode.get().value);
    const auto typeKey = toTypeKey(node);

    functionType = context.typeTable().findFunction(typeKey);

    if (!functionType)
    {
        functionType = createFunctionType(logger, context, node);
        context.typeTable().add(functionType);
    }

    std::shared_ptr<FunctionSymbol> symbol{};

    const auto functionName = toName(node.identifierNode.get().value);

    symbol->setName(functionName);
    symbol->setType(functionType);

    return symbol;
}

asg::Function process(logger::ILogger& logger, Context& context, const ast::FuncNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Function function{};

    const auto functionName = toName(node.identifierNode.get().value);

    function.name = functionName;

//    std::shared_ptr<FunctionSymbol> symbol = scope.symbolTable().findFunction(functionName);
//
////    if (symbol) throw DuplicateSymbolException(symbol);
//    if (symbol) throw DuplicateSymbolException();
////    if (symbol) throw RedeclarationException(symbol);

//    auto symbol = std::make_shared<FunctionSymbol>(functionName);
    auto symbol = createFunctionSymbol(logger, context, node);

//    const auto name = toName(node.identifierNode.get().value);
    const auto typeKey = toTypeKey(node);

    std::shared_ptr<FunctionType> functionType = context.typeTable().findFunction(typeKey);

    if (!functionType)
    {
        functionType = createFunctionType(node);
        context.typeTable().add(functionType);
    }

    symbol->setType(functionType);

    scope.symbolTable().add(symbol);

    scope.pushExpectedTypes({function.returnType});

    if (node.optionalStatblockNode)
    {
        const auto& statblockNode = node.optionalStatblockNode.get();

//        Statblock statblock = boost::get<asg::Statblock>(operator()(statblockNode));
        Statblock statblock = process(logger, context, statblockNode.get());

        function.body = statblock;
    }

//    variable.type = &resolve(node.typeNode.get());
//    variable.name = toName(node.identifierNode.get().value);
//
//    if (node.initListOrExprOrArgList)
//    {
//        variable.value = resolve(node.initListOrExprOrArgList.get());
//    }

    scope.popExpectedTypes();

    return function;
}

}}}