#include "analyzer/detail/TypeKeyResolver.hpp"

#include "analyzer/detail/Scope.hpp"
#include "analyzer/detail/TypeNameResolver.hpp"
// #include "analyzer/detail/TypeKeyResolverVisitor.hpp"

#include "type/PrimitiveType.hpp"

#include "detail/Format.hpp"
#include "type/Type.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

std::string resolveTypeKey(const Type::TypeId typeId)
{
    switch (typeId)
    {
        case Type::TypeId::VOID_T: return "v_void";
        case Type::TypeId::BOOLEAN: return "v_bool";
        case Type::TypeId::INTEGER8: return "v_int8";
        case Type::TypeId::INTEGER16: return "v_int16";
        case Type::TypeId::INTEGER32: return "v_int32";
        case Type::TypeId::INTEGER: return "v_int";
        case Type::TypeId::INTEGER64: return "v_int64";
        case Type::TypeId::UINTEGER8: return "v_uint8";
        case Type::TypeId::UINTEGER16: return "v_uint16";
        case Type::TypeId::UINTEGER32: return "v_uint32";
        case Type::TypeId::UINTEGER: return "v_uint";
        case Type::TypeId::UINTEGER64: return "v_uint64";
        case Type::TypeId::FLOAT: return "v_float";
        case Type::TypeId::DOUBLE: return "v_double";
    }

    throw InvalidArgumentException("");
}

std::string resolveTypeKey(const ast::PrimitiveType primitiveType)
{
    return resolveTypeKey(ice_script::PrimitiveType::toTypeId(primitiveType));
}

std::string resolveTypeKey(const Context& context, const ast::TypeNode& node)
{
    const auto name = resolveTypeName(node.datatypeNode);
    
    const auto& classTypes = context.typeTable().findClass(name);
    
    if (!classTypes.empty())
    {
        const auto& classType = classTypes.at(0);
        
        return classType->key();
    }
    
//        const auto& scopeNode = node.scopeNode;

    uint32_t qualifiers = ice_script::TypeQualifier::NONE;
    for (const auto qualifier : node.typeQualifiers) qualifiers |= qualifier;
    // if (node.typeQualifiers) qualifiers = node.typeQualifiers.get();
    
    ice_script::TypeModifier modifier = node.typeModifier.get_value_or(ice_script::TypeModifier::VALUE);
    
    if (!node.array.empty())
    {
        const auto arrayElementTypeKey = resolveArrayElementTypeKey(context, node);
        
        return toArrayTypeKey(qualifiers, arrayElementTypeKey, node.array, modifier);
    }
    
    return toTypeKey(name, qualifiers, modifier); //TypeModifier::NONE);
}

std::string resolveTypeKey(const Context& context, const ast::ClassNode& node)
{   
    return ice_script::detail::format(
        "%s%s%s",
        // (node.constant ? "c_" : ""),
        "",
        // (modifiers_ & TypeModifier::VALUE ? "v_" : (modifiers_ & TypeModifier::REFERENCE ? "r_" : (modifiers_ & TypeModifier::POINTER ? "p_" : ""))),
        "v_",
        resolveTypeName(node.identifierNode.get())
    );
}

std::string resolveTypeKey(const Context& context, const ast::FuncNode& node)
{
    std::string returnTypeKey{};
    if (node.value1)
    {
        const auto& tupleTypeOptionalString = boost::get<ast::TupleTypeOptionalStringType>(node.value1.get());
        const auto& typeNode = tupleTypeOptionalString.get<0>();

        returnTypeKey = resolveTypeKey(context, typeNode.get());
    }
    else
    {
        const auto candidates = context.typeTable().findClass(node.identifierNode.get().value);
        
        for (const auto& candidate : candidates)
        {
            const auto fullyQualifiedScopeName = ice_script::detail::format(
                "%s%s%s",
                candidate->fullyQualifiedScopeName(),
                boost::algorithm::ends_with(candidate->fullyQualifiedScopeName(), "::") ? "" : "::",
                candidate->name()
            );
            
            if (fullyQualifiedScopeName == context.scope().fullyQualifiedName())
            {
                returnTypeKey = candidate->key();
                break;
            }
        }
        
        // TODO
        if (returnTypeKey.empty())
        {
            throw RuntimeException("");
        }
    }
    
    // Is this a function from a class?
    std::shared_ptr<Type> classType{};
    
    auto* classScope = &context.scope();
    
    while (classScope && classScope->type() != ScopeType::CLASS)
    {
        classScope = classScope->parent();
    }
    
    if (classScope)
    {
        const auto& classSymbol = classScope->valueSymbol();
        classType = classSymbol->type();
    }
    
    std::vector<std::string> parameterTypeKeys{};
    for (const auto& value : node.paramlistNode.get().value)
    {
        parameterTypeKeys.push_back(resolveTypeKey(context, value));
    }
    
    return toFunctionTypeKey(
        returnTypeKey,
        // resolveTypeName(node.identifierNode.get()),
        classType ? classType->key() : "",
        parameterTypeKeys
    );
}

std::string resolveTypeKey(const Context& context, const ast::TypeTypeModIdentifierExpr& node)
{
    return resolveTypeKey(context, node.typeNode.get());
}

std::string resolveTypeKey(const Context& context, const ast::VarNode& node)
{
    return resolveTypeKey(context, node.typeNode.get());
}

std::string resolveArrayElementTypeKey(const Context& context, const ast::TypeNode& node)
{
    auto elementTypeNode = ast::TypeNode(node);
    
    elementTypeNode.array = {};
    
    return resolveTypeKey(context, elementTypeNode);
}

}}}