#include "analyzer/detail/analyzers/ForNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::For process(logger::ILogger& logger, Context& context, const ast::ForNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    For forStatement{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return forStatement;
}

}}}