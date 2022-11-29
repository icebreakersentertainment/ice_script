#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "analyzer/detail/SymbolTablePassVisitor.hpp"

#include "analyzer/detail/Scope.hpp"
#include "analyzer/detail/TypeKeyResolver.hpp"
#include "analyzer/detail/TypeNameResolver.hpp"
#include "analyzer/detail/SymbolKeyResolver.hpp"

#include "analyzer/detail/AnalyzerUtilities.hpp"

#include "type/ArrayType.hpp"

#include "symbol/OperatorSymbol.hpp"

#include "detail/Assert.hpp"

#include "exceptions/DuplicateSymbolException.hpp"

// Adapted from: https://stackoverflow.com/a/45677131
template<int N, typename... Ts> using NthTypeOf = typename std::tuple_element<N, std::tuple<Ts...>>::type;

template<int N, typename... Ts>
auto& get(boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

template<int N, typename... Ts>
auto& get(const boost::variant<Ts...>& v)
{
    using target = NthTypeOf<N, Ts...>;
    return boost::get<target>(v);
}

namespace ice_script { namespace analyzer { namespace detail {

using namespace ranges;
using namespace ranges::views;

using namespace ice_script::ast;
using namespace ice_script::asg;

inline std::shared_ptr<Symbol> createSymbol(const Context& context, const TypeTypeModIdentifierExpr& typeTypeModIdentifierExpr)
{
//    std::shared_ptr<Type> type{};

    const auto typeKey = resolveTypeKey(context, typeTypeModIdentifierExpr.typeNode.get());
    
    const auto type = context.typeTable().getByKey(typeKey);
    
    const auto name = typeTypeModIdentifierExpr.optionalIdentifierNode.get().get().value;

    if (!context.scope().symbolTable().find(name).empty()) throw DuplicateSymbolException();

//    type = context.typeTable().find(typeKey);

//    if (!type)
//    {
//        type = createFunctionType(context, node);
//        context.typeTable().add(type);
//    }

    auto symbol = std::make_shared<Symbol>(name);

    symbol->setType(type);
    symbol->setFullyQualifiedScopeName(context.scope().fullyQualifiedName());

    return symbol;
}

inline std::shared_ptr<Symbol> createSymbol(const Context& context, const std::shared_ptr<Type>& type)
{
    auto symbol = std::make_shared<Symbol>();

    symbol->setName(type->name());
    symbol->setType(type);
    // symbol->setOwnerSymbol(arraySymbol);
    
    return symbol;
}

inline std::shared_ptr<ArraySymbol> createArraySymbol(const Context& context, const std::shared_ptr<ArrayType>& arrayType)
{
    auto arraySymbol = std::make_shared<ArraySymbol>();

    arraySymbol->setName(arrayType->name());
    arraySymbol->setType(arrayType);
    // arraySymbol->setFullyQualifiedScopeName(context.scope().fullyQualifiedName());
    
    for (const auto& constructorType : arrayType->constructors())
    {
        auto constructorSymbol = std::make_shared<FunctionSymbol>();
        constructorSymbol->setName(arraySymbol->name());
        // defaultConstructor->setReturnType(context_->typeTable().get(ast::PrimitiveType::VOID_T));
        constructorSymbol->setOwnerSymbol(arraySymbol);
        constructorSymbol->setType(constructorType);
        // defaultConstructor->setParameters();
        
        arraySymbol->constructors().add(constructorSymbol);
    }
    
    for (const auto& operatorType : arrayType->operators())
    {
        auto operatorSymbol = std::make_shared<OperatorSymbol>();
        operatorSymbol->setName(operatorType->name());
        // defaultConstructor->setReturnType(context_->typeTable().get(ast::PrimitiveType::VOID_T));
        operatorSymbol->setOwnerSymbol(arraySymbol);
        operatorSymbol->setType(operatorType);
        
        auto parameterSymbols = operatorType->parameters()
            | transform([&](const auto& parameterType) { return createSymbol(context, parameterType); })
            | to<std::vector>()
            ;
        
        operatorSymbol->parameters().add(parameterSymbols);
        
        std::cout << "1: " << operatorSymbol->key() << ", " << operatorSymbol->type()->key() << std::endl;
        arraySymbol->operators().add(operatorSymbol);
    }

    return arraySymbol;
}

void SymbolTablePassVisitor::operator()(const Ast& ast) const
{
    operator()(ast.root);
}

void SymbolTablePassVisitor::operator()(const Root& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.scriptNode);
}

void SymbolTablePassVisitor::operator()(const ScriptNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& _node: node.value)
    {
        boost::apply_visitor(*this, _node);
    }
}

void SymbolTablePassVisitor::operator()(const ClassNode& node) const
{
    LOG_DEBUG((&context_->logger()), "Analyzing %s", typeid(node).name())

    // const auto name = node.identifierNode.get().value;
    const auto name = node.identifierNode.get().value;
    // const auto symbolName = resolveSymbolKey(*context_, node);
    // const auto fullyQualifiedSymbolName = resolveFullyQualifiedSymbolName(*context_, node);
    // const auto key = resolveSymbolKey(*context_, node);

    // const auto existing = symbolTable_->findClassByKey(key);

    // if (existing)
    // {
    //     throw DuplicateSymbolException();
    // }

    Scope& oldScope = context_->scope();
    Scope& newScope = context_->pushScope(name, ScopeType::CLASS);

//    if (node.value)
//    {
//        if (node.value.get().extendsAndImplements)
//        {
//            for (const auto& extendsAndImplements: node.value.get().extendsAndImplements.get())
//            {
//                operator()(extendsAndImplements);
//            }
//        }
//
//        for (const auto& virtualPropertyFunctionVariableFunctionDefinition : node.value.get().virtualPropertyFunctionVariableFunctionDefinitions)
//        {
//            boost::apply_visitor(*this, virtualPropertyFunctionVariableFunctionDefinition);
//        }
//    }

    auto symbol = std::make_shared<ClassSymbol>();

    symbol->setName(name);
    symbol->setFullyQualifiedScopeName(oldScope.fullyQualifiedName());
    // symbol->setKey(key);
    
    const auto typeKey = resolveTypeKey(*context_, node);

    auto type = context_->typeTable().getClassByKey(typeKey);

    symbol->setType(type);
    
    oldScope.symbolTable().add(symbol);
    newScope.symbolTable().add(symbol);

    context_->set(symbol);
    newScope.setValueSymbol(symbol);

    if (node.value)
    {
        const ClassData classData = node.value.get();

        for (const auto& virtualPropertyFunctionVariableFunctionDefinition : classData.virtualPropertyFunctionVariableFunctionDefinitions)
        {
            boost::apply_visitor(*this, virtualPropertyFunctionVariableFunctionDefinition);
        }
    }
    
    // Add default constructor if we have no constructors defined
    if (symbol->constructors().empty())
    {
        auto constructorTypes = symbol->type()->constructors();
        
        ICE_SCRIPT_ASSERT(!constructorTypes.empty());
        
        auto defaultConstructorType = constructorTypes[0];
        
        auto defaultConstructor = std::make_shared<FunctionSymbol>();
        defaultConstructor->setName(symbol->name());
        // defaultConstructor->setReturnType(context_->typeTable().get(ast::PrimitiveType::VOID_T));
        defaultConstructor->setOwnerSymbol(symbol);
        defaultConstructor->setType(defaultConstructorType);
        // defaultConstructor->setParameters();
        
        symbolTable_->add(defaultConstructor);
        
        symbol->constructors().add(defaultConstructor);
    }
    
    const auto constReferenceClassType = context_->typeTable().find(symbol->type(), symbol->type()->qualifiers() | TypeQualifier::TypeQualifierFlags::CONSTANT, TypeModifier::REFERENCE);
    
    // Add default copy constructor if we have no copy constructor defined
    if (symbol->constructors().findByParameterTypes({constReferenceClassType}).empty())
    {
        auto copyConstructorTypes = symbol->type()->constructors().findByParameterTypes({constReferenceClassType});
        
        ICE_SCRIPT_ASSERT(copyConstructorTypes.size() == 1);
        
        auto copyConstructorType = copyConstructorTypes[0];
        
        auto parameter = std::make_shared<Symbol>();
        parameter->setName("other");
        // parameter->setReturnType(context_->typeTable().get(ast::PrimitiveType::VOID_T));
        // parameter->setOwnerSymbol(symbol);
        parameter->setType(constReferenceClassType);
        
        auto copyConstructor = std::make_shared<FunctionSymbol>();
        copyConstructor->setName(symbol->name());
        // copyConstructor->setReturnType(context_->typeTable().get(ast::PrimitiveType::VOID_T));
        copyConstructor->setOwnerSymbol(symbol);
        copyConstructor->setType(copyConstructorType);
        copyConstructor->parameters().add(parameter);
        
        symbolTable_->add(copyConstructor);
        
        symbol->constructors().add(copyConstructor);
    }

    symbolTable_->add(symbol);
    
    context_->set(std::shared_ptr<ClassSymbol>{});

    context_->popScope();
}

void SymbolTablePassVisitor::operator()(const TypedefNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.primTypeNode);
    operator()(node.identifierNode);
}

void SymbolTablePassVisitor::operator()(const NamespaceNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const FuncNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    // const auto symbolKey = resolveSymbolKey(*context_, node);

    // const auto existing = symbolTable_->findFunctionByKey(symbolKey);

    // if (existing)
    // {
    //     throw DuplicateSymbolException();
    // }

    Scope& oldScope = context_->scope();
    Scope& newScope = context_->pushScope(name, ScopeType::FUNCTION);

    auto symbol = std::make_shared<FunctionSymbol>();

    symbol->setName(name);
    
    const auto typeKey = resolveTypeKey(*context_, node);

    auto type = context_->typeTable().getFunctionByKey(typeKey);

    symbol->setType(type);
    
    auto classSymbol = context_->classSymbol();
    
    if (classSymbol) symbol->setOwnerSymbol(classSymbol);
    
    context_->set(symbol);

//    operator()(node.identifierNode);

    if (node.value1)
    {
        operator()(node.value1);
    }

    operator()(node.paramlistNode);

    if (node.optionalStatblockNode)
    {
        operator()(node.optionalStatblockNode.get());
    }
    
    if (classSymbol)
    {
        if (node.value1)
        {
            classSymbol->functions().add(symbol);
        }
        else
        {
            classSymbol->constructors().add(symbol);
        }
    }

    symbolTable_->add(symbol);
    
    context_->set(std::shared_ptr<FunctionSymbol>{});

    context_->popScope();
}

void SymbolTablePassVisitor::operator()(const InterfaceNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const VarNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
    
    const auto& name = node.identifierNode.get().value;
    
    Scope& scope = context_->scope();
    
    auto symbol = std::make_shared<Symbol>();
    
    symbol->setName(name);
    
    const auto typeKey = resolveTypeKey(*context_, node);

    auto type = context_->typeTable().getByKey(typeKey);
    
    if (type->typeId() == Type::TypeId::ARRAY)
    {
        const auto& arrayType = std::dynamic_pointer_cast<ArrayType>(type);
        
        ICE_SCRIPT_ASSERT(arrayType);
        
        auto arraySymbol = createArraySymbol(*context_, arrayType);
        
        for (const auto& constructorSymbol : arraySymbol->constructors())
        {
            symbolTable_->add(constructorSymbol);
        }
        
        symbolTable_->add(arraySymbol);
    }
    
    symbol->setType(type);
    symbol->setFullyQualifiedScopeName(scope.fullyQualifiedName());
    
    if (scope.type() == ScopeType::GLOBAL) symbol->setGlobal(true);
    
    auto classSymbol = context_->classSymbol();
    
    if (classSymbol)
    {
        symbol->setOwnerSymbol(classSymbol);
        classSymbol->memberVariables().add(symbol);
    }

//    operator()(node.identifierNode);
    operator()(node.typeNode);

    if (node.initListOrExprOrArgList)
    {
        boost::apply_visitor(*this, node.initListOrExprOrArgList.get());

//        if (node.initListOrExprOrArgList.get().which() == 0)
//        {
//            const auto& v = get<0>(node.initListOrExprOrArgList.get());
//
//            boost::apply_visitor(*this, v);
//        }
//        else
//        {
////            operator()(get<1>(node.initListOrExprOrArgList.get()));
//        }
    }
    
    symbolTable_->add(symbol);
}

void SymbolTablePassVisitor::operator()(const ImportNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const EnumNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const FuncdefNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const VirtpropNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const MixinNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const IntfmthdNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const StatblockNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& value : node.value)
    {
        boost::apply_visitor(*this, value);
    }
}

void SymbolTablePassVisitor::operator()(const ParamlistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
    
    auto functionSymbol = context_->functionSymbol();
    
    if (functionSymbol)
    {
        for (const auto& parameter : node.value)
        {
            functionSymbol->parameters().add(createSymbol(*context_, parameter));
        }
    }

    // for (const auto& value : node.value)
    // {
    //     operator()(value.typeNode);
    // }
}

void SymbolTablePassVisitor::operator()(const TypemodNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const TypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    // isConst
    operator()(node.scopeNode);
    operator()(node.datatypeNode);
    // templates

//        boost::apply_visitor(*this(os_, printLocationInfo_, indent_+TAB_SIZE), node.value);
}

void SymbolTablePassVisitor::operator()(const InitlistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ScopeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const DatatypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const PrimtypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.primitiveType) << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const FuncattrNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    
//    os_ << node.value.size() << " ";
//    for (const auto& e: node.value)
//    {
//        os_ << e << " ";
//    }
//    os_ << std::endl;

//        operator()(node.isRef);
//
//        if (node.inout)
//        {
//            
//            operator()(node.inout.get());
//        }
}

void SymbolTablePassVisitor::operator()(const StatementNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const SwitchNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const BreakNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ForNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.varOrExprstatNode);

    operator()(node.exprstatNode);

    for (const auto& assignNode : node.assignNodes)
    {
        operator()(assignNode);
    }

    operator()(node.statementNode);
}

void SymbolTablePassVisitor::operator()(const WhileNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const DowhileNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const IfNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.assignNode);
    operator()(node.statementNode);

    if (node.optionalStatementNode)
    {
        operator()(node.optionalStatementNode);
    }
}

void SymbolTablePassVisitor::operator()(const ContinueNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ExprstatNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    if (node.value)
    {
        operator()(node.value);
    }
}

void SymbolTablePassVisitor::operator()(const TryNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ReturnNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    if (node.value)
    {
        operator()(node.value);
    }
}

void SymbolTablePassVisitor::operator()(const CaseNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ExprNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.exprtermNode);

    for (const auto& expropNodeAndExprtermNode : node.expropNodeAndExprtermNodes)
    {
        operator()(expropNodeAndExprtermNode.expropNode);
        operator()(expropNodeAndExprtermNode.exprtermNode);
    }
}

void SymbolTablePassVisitor::operator()(const ExprtermNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    if (node.value.which() == 2)
    {
        const auto& exprpreopsExprvalueExprpostops = get<2>(node.value);

        const auto& exprPreopNodes = exprpreopsExprvalueExprpostops.exprPreopNodes;

        for (const auto& exprPreopNode : exprPreopNodes) operator()(exprPreopNode);

        const auto& exprValueNode = exprpreopsExprvalueExprpostops.exprValueNode;

        operator()(exprValueNode);

        const auto& exprPostopNodes = exprpreopsExprvalueExprpostops.exprPostopNodes;

        for (const auto& exprPostopNode : exprPostopNodes) operator()(exprPostopNode);
    }
}

void SymbolTablePassVisitor::operator()(const ExprvalueNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const ConstructcallNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.typeNode);
    operator()(node.arglistNode);
}

void SymbolTablePassVisitor::operator()(const ExprpreopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const ExprpostopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const CastNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const LambdaNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const LiteralNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const FunccallNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.scopeNode);
    operator()(node.identifierNode);
    operator()(node.arglistNode);
}

void SymbolTablePassVisitor::operator()(const VaraccessNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.identifierNode);
}

void SymbolTablePassVisitor::operator()(const ArglistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& argument : node.value)
    {
        operator()(argument.assignNode);
    }
}

void SymbolTablePassVisitor::operator()(const AssignNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.conditionNode);

    if (node.assignopAssignNode)
    {
        operator()(node.assignopAssignNode.get().assignopNode);
        operator()(node.assignopAssignNode.get().assignNode);
    }
}

void SymbolTablePassVisitor::operator()(const ConditionNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.exprNode);

    if (node.assignNode)
    {
        operator()(boost::get<0>(node.assignNode.get()));
        operator()(boost::get<1>(node.assignNode.get()));
    }
}

void SymbolTablePassVisitor::operator()(const ExpropNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void SymbolTablePassVisitor::operator()(const BitopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const MathopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.mathOperator) << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const CompopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.comparisonOperator) << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const LogicopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.logicOperator) << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const AssignopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.assignOperator) << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const IdentifierNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << node.value << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const NumberNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << node.value << "]" << std::endl;
}

void SymbolTablePassVisitor::operator()(const StringNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const BitsNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const BoolNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const NullNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const VoidNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

// void SymbolTablePassVisitor::operator()(const OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType& node) const
// {
//     LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
// }

void SymbolTablePassVisitor::operator()(const boost::recursive_wrapper<AssignNode>& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const PostfixOperator& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void SymbolTablePassVisitor::operator()(const TupleTypeOptionalStringType& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

}}}