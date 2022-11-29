#include <boost/algorithm/string/predicate.hpp>

#include "analyzer/detail/SymbolKeyResolver.hpp"
#include "analyzer/detail/TypeKeyResolver.hpp"
#include "analyzer/detail/TypeNameResolver.hpp"

// #include "type/PrimitiveType.hpp"
#include "symbol/Symbols.hpp"

#include "detail/Format.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
// using namespace ice_script::asg;

bool argumentsMatch(const Context& context, const Symbols& parameters, const ArglistNode& arglistNode)
{
    // for (const auto& argument : arglistNode.value)
    // for (size_t i = 0; i < arglistNode.value.size(); ++i)
    // {
    //     const auto& condition = arglistNode.value[i].assignNode.get().condition.get();
    //     const auto typeKey = resolveTypeKey(context, condition);
        
    //     // const auto& identifierNode = boost::get<0>(argument.identifier.get());
        
    //     // const auto name = identifierNode.get().value;
        
    //     // auto type = context.typeTable().find(name).at(0);
    //     const auto& type = context.typeTable().getByKey(typeKey);
        
    //     if (type.get() != parameters[index]->type().get()) return false;
    // }
    
    return true;
}

std::string resolveFullyQualifiedName(const Context& context, const std::string& name)
{
    const auto fullyQualifiedScopeName = context.scope().fullyQualifiedName();
    
    if (boost::algorithm::ends_with(fullyQualifiedScopeName, "::"))
    {
        return fullyQualifiedScopeName + name;
    }
    
    return fullyQualifiedScopeName + "::" + name;
}

// std::string resolveSymbolKey(const Context& context, const std::shared_ptr<ClassType>& type)
// {
//     return ice_script::detail::format(
//         "class_%s%s",
//         type->fullyQualifiedScopeName(),
//         boost::algorithm::ends_with(type->fullyQualifiedScopeName(), "::") ? type->name() : "::" + type->name()
//     );
// }

std::string resolveSymbolKey(const Context& context, const ast::TypeNode& node)
{
    const auto name = resolveTypeName(node.datatypeNode);
    
    return resolveFullyQualifiedName(context, name);
}

std::string resolveSymbolKey(const Context& context, const ast::ClassNode& node)
{
    const auto fullyQualifiedScopeName = context.scope().fullyQualifiedName();
    
    // return "class_" + resolveFullyQualifiedName(context, node.identifierNode.get().value);
    return "class_" + fullyQualifiedScopeName;
}

std::string resolveSymbolKey(const Context& context, const ast::FuncNode& node)
{
    // return "function_" + resolveFullyQualifiedName(context, node.identifierNode.get().value);
    
    const auto typeKey = resolveTypeKey(context, node);
    
    const auto& type = context.typeTable().getFunctionByKey(typeKey);
    
    const auto fullyQualifiedName = ice_script::detail::format(
        "%s%s%s",
        type->fullyQualifiedScopeName(),
        boost::algorithm::ends_with(type->fullyQualifiedScopeName(), "::") ? "" : "::",
        // type->ownerType() ? type->ownerType()->name() + "::" : "",
        node.identifierNode.get().value
    );
    
    std::stringstream ss{};
    // for (const auto& argument : node.arglistNode.get().value)
    for (size_t i=0; i < type->parameters().size(); ++i)
    {
        if (i > 0) ss << "_";
        
        ss << type->parameters()[i]->key();
    }
    
    auto parameters = ss.str();
    if (!parameters.empty()) parameters = "_" + parameters;
    
    return ice_script::detail::format(
        "function_%s%s",
        fullyQualifiedName,
        parameters
    );
}

std::string resolveSymbolKey(const Context& context, const ast::VarNode& node)
{
    if (context.scope().type() == ScopeType::FUNCTION)
    {
        return node.identifierNode.get().value;
    }
    
    return resolveFullyQualifiedName(context, node.identifierNode.get().value);
}

std::string resolveSymbolKey(const Context& context, const ast::ConstructcallNode& node)
{
    const auto classSymbolKey = resolveSymbolKey(context, node.typeNode.get());
    const auto classSymbol = context.symbolTable().getClassByKey(classSymbolKey);

    for (const auto& constructor : classSymbol->constructors())
    {
        if (argumentsMatch(context, constructor->parameters(), node.arglistNode.get()))
        {
            return constructor->key();
        }
    }

    // throw SymbolNotFoundException();
    throw InvalidArgumentException("");
}

}}}