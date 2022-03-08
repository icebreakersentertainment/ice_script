#include "analyzer/detail/analyzers/FuncdefNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Functiondefinition process(logger::ILogger& logger, Context& context, const ast::FuncdefNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Functiondefinition functiondefinition{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return functiondefinition;
}

}}}