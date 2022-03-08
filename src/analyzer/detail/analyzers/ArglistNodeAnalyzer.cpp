#include "analyzer/detail/analyzers/ArglistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Arglist process(logger::ILogger& logger, Context& context, const ast::ArglistNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Arglist arglist{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return arglist;
}

}}}