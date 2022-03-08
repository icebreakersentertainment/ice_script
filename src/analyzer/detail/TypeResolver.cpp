#include "analyzer/detail/TypeResolver.hpp"
#include "analyzer/detail/TypeResolverVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

// VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
// TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
// SCOPE         ::= ['::'] {IDENTIFIER '::'} [IDENTIFIER ['<' TYPE {',' TYPE} '>'] '::']
// DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
std::shared_ptr<asg::Type> resolve(logger::ILogger& logger, Context& context, const ast::TypeNode& node)
{
    Scope& scope = context.scope();

//        const auto& scopeNode = node.scopeNode;

    const auto& datatypeNode = node.datatypeNode;

    if (datatypeNode.value.type() == typeid(ast::IdentifierNode))
    {
        const auto& identifierNode = boost::get<ast::IdentifierNode>(datatypeNode.value);
        const auto className = toName(identifierNode.value);

        std::shared_ptr<asg::Type> type = context.typeTable().find(className);

        if (!type) type = context.typeTable().unknownType();

        return type;

//        return context_->typeTable().get(className);
    }
    else if (datatypeNode.value.type() == typeid(ast::PrimtypeNode))
    {
        const auto& primtypeNode = boost::get<ast::PrimtypeNode>(datatypeNode.value);

        return context.typeTable().get(primtypeNode.primitiveType);

//        return context_->typeTable().get(primtypeNode.primitiveType);
    }

    throw TypeNotFoundException();
}

// VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
// TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
// SCOPE         ::= ['::'] {IDENTIFIER '::'} [IDENTIFIER ['<' TYPE {',' TYPE} '>'] '::']
// DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
std::shared_ptr<asg::FunctionType> resolveFunctionType(logger::ILogger& logger, Context& context, const ast::TypeNode& node)
{
    const auto& datatypeNode = node.datatypeNode;

    if (datatypeNode.value.type() == typeid(ast::PrimtypeNode)) throw TypeNotFoundException();

    Scope& scope = context.scope();

//        const auto& scopeNode = node.scopeNode;

    if (datatypeNode.value.type() == typeid(ast::IdentifierNode))
    {
        const auto& identifierNode = boost::get<ast::IdentifierNode>(datatypeNode.value);
        const auto className = toName(identifierNode.value);

        std::shared_ptr<asg::FunctionType> type = context.typeTable().findFunction(className);

//        if (!type) type = context.typeTable().unknownType();

        return type;

//        return context_->typeTable().get(className);
    }

    throw TypeNotFoundException();
}

std::shared_ptr<asg::Type> resolveType(logger::ILogger& logger, Context& context, const asg::Expressionvalue& expressionvalue)
{
    TypeResolverVisitor visitor{logger, context};
    return boost::apply_visitor(visitor, expressionvalue.value);
}

std::shared_ptr<asg::Type> resolveType(logger::ILogger& logger, Context& context, const asg::Expressionpostoperator& expressionpostoperator)
{
    TypeResolverVisitor visitor{logger, context};
    return boost::apply_visitor(visitor, expressionpostoperator.value);
//    return {};
}

}}}