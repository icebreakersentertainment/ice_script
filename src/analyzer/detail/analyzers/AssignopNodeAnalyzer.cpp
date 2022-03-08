#include "analyzer/detail/analyzers/AssignopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Assignoperator process(logger::ILogger& logger, Context& context, const ast::AssignopNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Assignoperator assignoperator{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return assignoperator;
}

}}}