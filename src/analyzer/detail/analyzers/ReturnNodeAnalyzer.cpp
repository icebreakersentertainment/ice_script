#include "analyzer/detail/analyzers/ReturnNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Return process(logger::ILogger& logger, Context& context, const ast::ReturnNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Return returnStatement{};

    if (node.value)
    {
        returnStatement.assignment = process(logger, context, node.value.get().get());
    }

    return returnStatement;
}

}}}