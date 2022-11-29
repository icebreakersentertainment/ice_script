#include "analyzer/detail/analyzers/ConstructcallNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

#include "analyzer/detail/SymbolKeyResolver.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Constructcall process(Context& context, const ast::ConstructcallNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Constructcall constructcall{};

    const auto& identifierNode = boost::get<ast::IdentifierNode>(node.typeNode.get().datatypeNode.value);
    
    const auto candidates = context.symbolTable().findFunction(identifierNode.value);
    
    bool success = false;
    
    for (const auto& candidate : candidates)
    {
        if (!candidate->type()->isConstructor()) continue;
        if (candidate->parameters().size() != node.arglistNode.get().value.size()) continue;
        
        scope.pushExpectedTypes(candidate->type()->parameters().getAll());

        constructcall.symbol = candidate;
        constructcall.arglist = process(context, node.arglistNode.get());
        
        success = true;

        scope.popExpectedTypes();
        
        if (success) break;
    }
    
    if (!success) throw RuntimeException("");

    return constructcall;
}

}}}