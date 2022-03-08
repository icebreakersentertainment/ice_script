#include "analyzer/detail/analyzers/ScopeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Scoperatore process(logger::ILogger& logger, Context& context, const ast::ScopeNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Scoperatore scoperatore{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return scoperatore;
}

}}}