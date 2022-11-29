#include "analyzer/detail/analyzers/FunccallNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "analyzer/detail/SymbolKeyResolver.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Functioncall process(Context& context, const ast::FunccallNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Functioncall functioncall{};

    functioncall.name = node.identifierNode.get().value;
    
    const auto candidates = context.symbolTable().findFunction(functioncall.name);
    
    bool success = false;
    
    for (const auto& candidate : candidates)
    {
        if (candidate->parameters().size() != node.arglistNode.get().value.size()) continue;
        
        scope.pushExpectedTypes(candidate->type()->parameters().getAll());

        try
        {
            functioncall.symbol = candidate;
            functioncall.type = candidate->type();
            
            functioncall.arglist = process(context, node.arglistNode.get());
            
            success = true;
        }
        catch (const std::exception& e)
        {
            
        }

        scope.popExpectedTypes();
        
        if (success) break;
    }
    
    if (!success) throw RuntimeException("");
    
    // const auto symbolKey = resolveSymbolKey(context, node);

    // auto symbol = scope.symbolTable().getFunctionByKey(symbolKey);

    // functioncall.symbol = symbol;
    // functioncall.type = symbol->type();

    // scope.pushExpectedTypes(symbol->type()->parameters());

    // functioncall.arglist = process(context, node.arglistNode.get());

    // scope.popExpectedTypes();

    return functioncall;
}

}}}