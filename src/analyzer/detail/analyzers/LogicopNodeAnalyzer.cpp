#include "analyzer/detail/analyzers/LogicopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Logicoperator process(Context& context, const ast::LogicopNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Logicoperator logicoperator{};

    logicoperator.logicOperator = node.logicOperator;

    return logicoperator;
}

}}}