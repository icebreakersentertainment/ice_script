#include "analyzer/detail/analyzers/ExprpreopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionpreoperator process(logger::ILogger& logger, Context& context, const ast::ExprpreopNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionpreoperator expressionpreoperator{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return expressionpreoperator;
}

}}}