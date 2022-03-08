#include "analyzer/detail/analyzers/MathopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Mathoperator process(logger::ILogger& logger, Context& context, const ast::MathopNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Mathoperator mathoperator{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return mathoperator;
}

}}}