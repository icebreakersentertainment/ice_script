#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionstat process(Context& context, const ast::ExprstatNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionstat expressionstat{};

    if (node.value)
    {
        expressionstat.assign = process(context, node.value.get().get());
    }

    return expressionstat;
}

}}}