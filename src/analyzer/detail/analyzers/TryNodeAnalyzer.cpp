#include "analyzer/detail/analyzers/TryNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Try process(logger::ILogger& logger, Context& context, const ast::TryNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Try tryStatement{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return tryStatement;
}

}}}