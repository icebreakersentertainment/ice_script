#include "analyzer/detail/analyzers/CastNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Cast process(logger::ILogger& logger, Context& context, const ast::CastNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Cast cast{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return cast;
}

}}}