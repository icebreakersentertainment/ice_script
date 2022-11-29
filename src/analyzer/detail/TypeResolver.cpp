#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/TypeResolverVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

std::shared_ptr<Type> resolve(Context& context, const ast::TypeNode& node)
{
    Scope& scope = context.scope();

//        const auto& scopeNode = node.scopeNode;

    const auto& datatypeNode = node.datatypeNode;

    if (datatypeNode.value.type() == typeid(ast::IdentifierNode))
    {
        const auto& identifierNode = boost::get<ast::IdentifierNode>(datatypeNode.value);
        const auto className = toName(identifierNode.value);

        auto types = context.typeTable().find(className);

        return types.empty() ? context.typeTable().unknownType() : types[0];
    }
    else if (datatypeNode.value.type() == typeid(ast::PrimtypeNode))
    {
        const auto& primtypeNode = boost::get<ast::PrimtypeNode>(datatypeNode.value);

        return context.typeTable().get(primtypeNode.primitiveType);
    }

    throw TypeNotFoundException();
}

std::shared_ptr<FunctionType> resolveFunctionType(Context& context, const ast::TypeNode& node)
{
    const auto& datatypeNode = node.datatypeNode;

    if (datatypeNode.value.type() == typeid(ast::PrimtypeNode)) throw TypeNotFoundException();

    Scope& scope = context.scope();

//        const auto& scopeNode = node.scopeNode;

    if (datatypeNode.value.type() == typeid(ast::IdentifierNode))
    {
        const auto& identifierNode = boost::get<ast::IdentifierNode>(datatypeNode.value);
        const auto className = toName(identifierNode.value);

        auto types = context.typeTable().findFunction(className);

//        if (!type) type = context.typeTable().unknownType();

        return types[0];
    }

    throw TypeNotFoundException();
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Assign& assign)
{
    if (!assign.functioncall)
    {
        return resolveType(context, assign.condition.get());
    }
    else
    {
        return assign.functioncall.get().get().type->returnType();
    }
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Condition& condition)
{
    return resolveType(context, condition.expression.get());
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Expression& expression)
{
    if (!expression.functioncall)
    {
        return resolveType(context, expression.expressionterm.get());
    }
    else
    {
        return expression.functioncall.get().get().type->returnType();
    }
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionterm& expressionterm)
{
    const auto& exprpreopsExprvalueExprpostops = boost::get<ExprpreopsExprvalueExprpostops>(expressionterm.value);
    const auto& expressionvalue = exprpreopsExprvalueExprpostops.expressionValue;
    
    if (!exprpreopsExprvalueExprpostops.expressionPostoperators.empty())
    {
        const auto& expressionpostoperator = exprpreopsExprvalueExprpostops.expressionPostoperators.back().get();
        
        return resolveType(context, expressionpostoperator);
    }

    return resolveType(context, expressionvalue);
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionvalue& expressionvalue)
{
    return boost::apply_visitor(TypeResolverVisitor(context), expressionvalue.value);
}

std::shared_ptr<Type> resolveType(Context& context, const asg::Expressionpostoperator& expressionpostoperator)
{
    return boost::apply_visitor(TypeResolverVisitor(context), expressionpostoperator.value);
}

std::shared_ptr<Type> resolveType(Context& context, const asg::ExprpreopsExprvalueExprpostops& exprpreopsExprvalueExprpostops)
{
    if (!exprpreopsExprvalueExprpostops.expressionPostoperators.empty())
    {
        return resolveType(context, exprpreopsExprvalueExprpostops.expressionPostoperators.back().get());
    }
    else
    {
        return resolveType(context, exprpreopsExprvalueExprpostops.expressionValue);
    }
}

}}}