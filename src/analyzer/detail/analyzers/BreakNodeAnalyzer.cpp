#include "analyzer/detail/analyzers/BreakNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Break process(logger::ILogger& logger, Context& context, const ast::BreakNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Break breakStatement{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return breakStatement;
}

}}}