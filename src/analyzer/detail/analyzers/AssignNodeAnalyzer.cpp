#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ConditionNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Assign process(logger::ILogger& logger, Context& context, const ast::AssignNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Assign assign{};

    assign.condition = process(logger, context, node.conditionNode.get());

    return assign;
}

}}}