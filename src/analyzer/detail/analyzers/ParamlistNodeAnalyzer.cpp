#include "analyzer/detail/analyzers/ParamlistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Parameterlist process(logger::ILogger& logger, Context& context, const ast::ParamlistNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Parameterlist parameterlist{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return parameterlist;
}

}}}