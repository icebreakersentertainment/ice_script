#include "analyzer/detail/analyzers/CompopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Comparisonoperator process(Context& context, const ast::CompopNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Comparisonoperator comparisonoperator{};

    comparisonoperator.comparisonOperator = node.comparisonOperator;

    return comparisonoperator;
}

}}}