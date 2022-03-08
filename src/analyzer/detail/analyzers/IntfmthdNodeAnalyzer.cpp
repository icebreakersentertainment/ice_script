#include "analyzer/detail/analyzers/IntfmthdNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Interfacemethod process(logger::ILogger& logger, Context& context, const ast::IntfmthdNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Interfacemethod interfacemethod{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return interfacemethod;
}

}}}