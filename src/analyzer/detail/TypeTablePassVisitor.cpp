#include <range/v3/view.hpp>
#include <range/v3/view/any_view.hpp>

#include "analyzer/detail/TypeTablePassVisitor.hpp"

#include "analyzer/detail/TypeKeyResolver.hpp"
#include "analyzer/detail/TypeNameResolver.hpp"

#include "analyzer/detail/AnalyzerUtilities.hpp"
#include "analyzer/detail/TypeTableUtilities.hpp"

#include "type/ClassType.hpp"

#include "analyzer/detail/TypeResolver.hpp"

#include "exceptions/DuplicateTypeException.hpp"

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

void TypeTablePassVisitor::operator()(const Ast& ast) const
{
    operator()(ast.root);
}

void TypeTablePassVisitor::operator()(const Root& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.scriptNode);
}

void TypeTablePassVisitor::operator()(const ScriptNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& _node: node.value)
    {
        boost::apply_visitor(*this, _node);
    }
}

void TypeTablePassVisitor::operator()(const ClassNode& node) const
{
    LOG_DEBUG((&context_->logger()), "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    
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

    auto type = std::make_shared<ClassType>();

    type->setName(name);
    type->setFullyQualifiedScopeName(oldScope.fullyQualifiedName());
    // type->setKey(key);

    context_->set(type);

    if (node.value)
    {
        const ClassData classData = node.value.get();

        for (const auto& virtualPropertyFunctionVariableFunctionDefinition : classData.virtualPropertyFunctionVariableFunctionDefinitions)
        {
            boost::apply_visitor(*this, virtualPropertyFunctionVariableFunctionDefinition);
        }
    }

    // Add default constructor if we have no constructors defined
    if (type->constructors().empty())
    {
        auto defaultConstructor = std::make_shared<FunctionType>();
        defaultConstructor->setName(type->name());
        defaultConstructor->setReturnType(type);
        defaultConstructor->setOwnerType(type);
        defaultConstructor->setIsMethod(true);
        defaultConstructor->setIsConstructor(true);

        type->constructors().add(defaultConstructor);
    }

    typeTable_->add(type);
    
    auto constValueType = std::make_shared<ClassType>(*type);
    constValueType->setQualifiers(TypeQualifier::CONSTANT);
    
    auto referenceType = std::make_shared<ClassType>(*type);
    referenceType->setModifier(TypeModifier::REFERENCE);
    
    auto constReferenceType = std::make_shared<ClassType>(*referenceType);
    constReferenceType->setQualifiers(TypeQualifier::CONSTANT);
    
    auto pointerType = std::make_shared<ClassType>(*type);
    pointerType->setModifier(TypeModifier::POINTER);

    auto constPointerType = std::make_shared<ClassType>(*pointerType);
    constPointerType->setQualifiers(TypeQualifier::CONSTANT);
    
    typeTable_->add(constValueType);
    typeTable_->add(referenceType);
    typeTable_->add(constReferenceType);
    typeTable_->add(pointerType);
    typeTable_->add(constPointerType);
    
    // Add default copy constructor if we have no copy constructor defined
    if (type->constructors().findByParameterTypes({constReferenceType}).empty())
    {
        auto copyConstructor = std::make_shared<FunctionType>();
        copyConstructor->setName(type->name());
        copyConstructor->setReturnType(type);
        copyConstructor->setOwnerType(type);
        copyConstructor->parameters().add(constReferenceType);
        copyConstructor->setIsMethod(true);
        copyConstructor->setIsConstructor(true);

        type->constructors().add(copyConstructor);
        constValueType->constructors().add(copyConstructor);
        referenceType->constructors().add(copyConstructor);
        constReferenceType->constructors().add(copyConstructor);
        pointerType->constructors().add(copyConstructor);
        constPointerType->constructors().add(copyConstructor);
    }

    context_->set(std::shared_ptr<ClassType>());
    context_->popScope();
}

void TypeTablePassVisitor::operator()(const TypedefNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.primTypeNode);
    operator()(node.identifierNode);
}

void TypeTablePassVisitor::operator()(const NamespaceNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const FuncNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    
    Scope& oldScope = context_->scope();
    Scope& newScope = context_->pushScope(name, ScopeType::FUNCTION);

    auto type = std::make_shared<FunctionType>();

    type->setName(name);
    type->setFullyQualifiedScopeName(oldScope.fullyQualifiedName());
    
    auto classType = context_->getClass();
    
    if (classType) type->setOwnerType(classType);
    
    context_->set(type);

//    operator()(node.identifierNode);

//    if (node.value1)
//    {
//        auto type = resolveType(context, node.value1.get());
//        operator()(node.value1);
//    }
//    else
//    {
//        auto voidType = typeTable_->find("void").at(0);
//        type->setReturnType(voidType);
//    }

    std::shared_ptr<Type> returnType{};

    if (node.value1)
    {
        const auto& tupleTypeOptionalString = boost::get<ast::TupleTypeOptionalStringType>(node.value1.get());
        const auto& typeNode = tupleTypeOptionalString.get<0>();

        const auto returnTypeKey = resolveTypeKey(*context_, typeNode.get());

        returnType = typeTable_->findByKey(returnTypeKey);

        if (!returnType)
        {
            // TODO
        }
    }
    else
    {
        returnType = classType;
    }

    type->setReturnType(returnType);

    operator()(node.paramlistNode);

    if (node.optionalStatblockNode)
    {
        operator()(node.optionalStatblockNode.get());
    }

    // If we are processing a class, add this function to the class
    if (classType)
    {
        type->setIsConstructor(true);
        
        classType->constructors().add(type);
    }
    // else
    // {
        typeTable_->add(type);
    // }

    context_->popScope();
}

void TypeTablePassVisitor::operator()(const InterfaceNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

auto createArrayTypes(Context& context, const ast::TypeNode& node)
{
    // std::vector<std::shared_ptr<ArrayType>> arrayTypes{};
    
    const auto arrayElementTypeKey = resolveArrayElementTypeKey(context, node);
            
    const auto& arrayElementType = context.typeTable().getByKey(arrayElementTypeKey);
    
    const auto arrayElementTypes = context.typeTable().findLike(arrayElementType);
    
    // ranges::any_view<std::shared_ptr<ArrayType>> arrayTypes{};
    // std::vector<std::shared_ptr<ArrayType>> arrayTypes{};
    
    std::vector<std::shared_ptr<ArrayType>> arrayTypes = arrayElementTypes
        | transform([&](const auto& arrayElementType) { return analyzer::createArrayTypes(context.typeTable(), arrayElementType, node.array); })
        | join
        | to<std::vector>()
        ;
    
    // for (const auto& type : arrayElementTypes)
    // {
    //     // arrayTypes = ranges::view::concat(arrayTypes, analyzer::createArrayTypes(type, node.array));
    //     auto tmp = analyzer::createArrayTypes(type, node.array);
    //     arrayTypes = ranges::views::concat(arrayTypes, tmp);
    // }
    
    // for (auto type : arrayTypes)
    // {
    //     type->constructors().add(createConstructorsForArrayType(arrayTypes, type));
    //     type->operators().add(createOperatorsForArrayType(arrayTypes, type));
    // }
    
    return arrayTypes;
    
    // const auto name = resolveTypeName(node.datatypeNode);
    
    // const auto& optionalDimension =  node.array[0];
    
    // arrayType->setName(ice_script::detail::format("%s[%s]", name, optionalDimension.get()));
    // arrayType->setType(arrayElementType);
    // arrayType->setDimensions({boost::optional<uint32_t>{optionalDimension.get()}});
    
    // return arrayType;
}

void TypeTablePassVisitor::operator()(const VarNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    const auto name = node.identifierNode.get().value;
    
    Scope& scope = context_->scope();
    
    const auto typeKey = resolveTypeKey(*context_, node.typeNode.get());

    auto type = typeTable_->findByKey(typeKey);
    
    if (!type)
    {
        if (!node.typeNode.get().array.empty())
        {
            const auto arrayElementTypeKey = resolveArrayElementTypeKey(*context_, node.typeNode.get());
            
            const auto arrayElementType = typeTable_->findByKey(arrayElementTypeKey);
            
            if (arrayElementType)
            {
                const auto types = createArrayTypes(*context_, node.typeNode.get());
                
                for (const auto& type : types) typeTable_->add(type);
                
                type = typeTable_->getByKey(typeKey);
            }
            else
            {
                // TODO
                throw RuntimeException("");
            }
        }
        else
        {
            // TODO
            throw RuntimeException("");
        }
    }
    
    auto classType = context_->getClass();
    
    if (classType)
    {
        classType->memberVariables().add(type);
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
}

void TypeTablePassVisitor::operator()(const ImportNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const EnumNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const FuncdefNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const VirtpropNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const MixinNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const IntfmthdNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const StatblockNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& value : node.value)
    {
        boost::apply_visitor(*this, value);
    }
}

void TypeTablePassVisitor::operator()(const ParamlistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    Scope& scope = context_->scope();

    auto type = context_->getFunction();

    for (const auto& value : node.value)
    {
        const auto parameterTypeKey = resolveTypeKey(*context_, value);

        const auto parameterType = typeTable_->findByKey(parameterTypeKey);

        if (!parameterType)
        {
            // TODO
        }

        type->parameters().add(parameterType);
//        operator()(value.typeNode);
    }
}

void TypeTablePassVisitor::operator()(const TypemodNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const TypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    // isConst
    operator()(node.scopeNode);
    operator()(node.datatypeNode);
    // templates

//        boost::apply_visitor(*this(os_, printLocationInfo_, indent_+TAB_SIZE), node.value);
}

void TypeTablePassVisitor::operator()(const InitlistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ScopeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const DatatypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const PrimtypeNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.primitiveType) << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const FuncattrNode& node) const
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

void TypeTablePassVisitor::operator()(const StatementNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const SwitchNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const BreakNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ForNode& node) const
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

void TypeTablePassVisitor::operator()(const WhileNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const DowhileNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const IfNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.assignNode);
    operator()(node.statementNode);

    if (node.optionalStatementNode)
    {
        operator()(node.optionalStatementNode);
    }
}

void TypeTablePassVisitor::operator()(const ContinueNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ExprstatNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    if (node.value)
    {
        operator()(node.value);
    }
}

void TypeTablePassVisitor::operator()(const TryNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ReturnNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    if (node.value)
    {
        operator()(node.value);
    }
}

void TypeTablePassVisitor::operator()(const CaseNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ExprNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.exprtermNode);

    for (const auto& expropNodeAndExprtermNode : node.expropNodeAndExprtermNodes)
    {
        operator()(expropNodeAndExprtermNode.expropNode);
        operator()(expropNodeAndExprtermNode.exprtermNode);
    }
}

void TypeTablePassVisitor::operator()(const ExprtermNode& node) const
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

void TypeTablePassVisitor::operator()(const ExprvalueNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const ConstructcallNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.typeNode);
    operator()(node.arglistNode);
}

void TypeTablePassVisitor::operator()(const ExprpreopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const ExprpostopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const CastNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const LambdaNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const LiteralNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const FunccallNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.scopeNode);
    operator()(node.identifierNode);
    operator()(node.arglistNode);
}

void TypeTablePassVisitor::operator()(const VaraccessNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.identifierNode);
}

void TypeTablePassVisitor::operator()(const ArglistNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    for (const auto& argument : node.value)
    {
        operator()(argument.assignNode);
    }
}

void TypeTablePassVisitor::operator()(const AssignNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.conditionNode);

    if (node.assignopAssignNode)
    {
        operator()(node.assignopAssignNode.get().assignopNode);
        operator()(node.assignopAssignNode.get().assignNode);
    }
}

void TypeTablePassVisitor::operator()(const ConditionNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    operator()(node.exprNode);

    if (node.assignNode)
    {
        operator()(boost::get<0>(node.assignNode.get()));
        operator()(boost::get<1>(node.assignNode.get()));
    }
}

void TypeTablePassVisitor::operator()(const ExpropNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    boost::apply_visitor(*this, node.value);
}

void TypeTablePassVisitor::operator()(const BitopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const MathopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.mathOperator) << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const CompopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.comparisonOperator) << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const LogicopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.logicOperator) << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const AssignopNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << toString(node.assignOperator) << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const IdentifierNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << node.value << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const NumberNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

//    os_ << "[" << node.value << "]" << std::endl;
}

void TypeTablePassVisitor::operator()(const StringNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const BitsNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const BoolNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const NullNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const VoidNode& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

// void TypeTablePassVisitor::operator()(const OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType& node) const
// {
//     LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
// }

void TypeTablePassVisitor::operator()(const boost::recursive_wrapper<AssignNode>& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const PostfixOperator& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())
}

void TypeTablePassVisitor::operator()(const TupleTypeOptionalStringType& node) const
{
    LOG_DEBUG(logger_, "Analyzing %s", typeid(node).name())

    const TypeNode& typeNode = boost::get<0>(node).get();
}

}}}