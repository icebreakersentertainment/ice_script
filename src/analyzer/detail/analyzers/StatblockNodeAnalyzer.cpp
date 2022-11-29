#include "analyzer/detail/analyzers/StatblockNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/StatblockNodeVisitor.hpp"

#include "ast/AstPrinter.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Statblock process(Context& context, const ast::StatblockNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Statblock statblock{};

    for (const auto& varNodeOrStatementNode : node.value)
    {
        StatblockNodeVisitor visitor{context};
        auto value = boost::apply_visitor(visitor, varNodeOrStatementNode);

        statblock.values.push_back(value);

//        if (varNodeOrStatementNode.type() == typeid(ast::VarNode))
//        {
//            const auto& varNode = boost::get<ast::VarNode>(varNodeOrStatementNode);
//
//            auto variable = operator()(varNode);
//
//            result.push_back();
//
//            const auto& tupleTypeOptionalString = boost::get<ast::TupleTypeOptionalStringType>(node.value1.get());
//            const auto& typeNode = tupleTypeOptionalString.get<0>();
//
//            Type& type = resolve(typeNode.get());
//
//            const auto functionName = toName(node.identifierNode.get().value);
//
//            Symbol* symbol = scope.symbolTable().find(functionName);
//
//        //        if (symbol) throw DuplicateSymbolException(symbol);
//            if (symbol) throw DuplicateSymbolException();
//        //        if (symbol) throw RedeclarationException(symbol);
//
//            symbol = &scope.symbolTable().create(functionName);
//            symbol->setType(type);
//        }
    }

    return statblock;
}

}}}