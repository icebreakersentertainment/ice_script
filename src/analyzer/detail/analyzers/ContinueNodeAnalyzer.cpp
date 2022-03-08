#include "analyzer/detail/analyzers/ContinueNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Continue process(logger::ILogger& logger, Context& context, const ast::ContinueNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Continue continueStatement{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return continueStatement;
}

}}}