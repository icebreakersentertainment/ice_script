#include "analyzer/detail/analyzers/AssignopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Assignoperator process(Context& context, const ast::AssignopNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Assignoperator assignoperator{};

    assignoperator.assignOperator = node.assignOperator;

    return assignoperator;
}

}}}