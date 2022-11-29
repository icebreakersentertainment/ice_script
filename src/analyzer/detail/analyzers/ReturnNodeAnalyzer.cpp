#include "analyzer/detail/analyzers/ReturnNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Return process(Context& context, const ast::ReturnNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Return returnStatement{};

    if (node.value)
    {
        const auto& expectedReturnTypes = context.expectedReturnTypes();
        
        scope.pushExpectedTypes(expectedReturnTypes);
        
        returnStatement.assignment = process(context, node.value.get().get());
        
        scope.popExpectedTypes();
    }

    return returnStatement;
}

}}}