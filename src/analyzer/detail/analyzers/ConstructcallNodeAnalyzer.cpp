#include "analyzer/detail/analyzers/ConstructcallNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Constructcall process(logger::ILogger& logger, Context& context, const ast::ConstructcallNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Constructcall constructcall{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return constructcall;
}

}}}