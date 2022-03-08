#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionstat process(logger::ILogger& logger, Context& context, const ast::ExprstatNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionstat expressionstat{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return expressionstat;
}

}}}