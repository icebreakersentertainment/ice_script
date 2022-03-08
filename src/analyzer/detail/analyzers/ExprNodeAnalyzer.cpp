#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ExprtermNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expression process(logger::ILogger& logger, Context& context, const ast::ExprNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expression expression{};

    expression.expressionterm = process(logger, context, node.exprtermNode.get());

    for (const auto& value : node.value)
    {
        Expressionoperatorerty expressionoperatorerty = process(logger, context, boost::get<0>(value).get());
        Expressionterm expressionterm = process(logger, context, boost::get<1>(value).get());

        expression.expressionOperationsAndExpressionTerms.push_back({expressionoperatorerty, expressionterm});
    }

    return expression;
}

}}}