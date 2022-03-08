#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Functioncall process(logger::ILogger& logger, Context& context, const ast::FunccallNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Functioncall functioncall{};

    const auto functionName = toName(node.identifierNode.get().value);

    functioncall.name = functionName;

    std::shared_ptr<FunctionSymbol> symbol = scope.symbolTable().findFunction(functionName);

    functioncall.type = symbol->type();



//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return functioncall;
}

}}}