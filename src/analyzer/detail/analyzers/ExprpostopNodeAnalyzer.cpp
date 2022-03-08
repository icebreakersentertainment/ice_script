#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionpostoperator process(logger::ILogger& logger, Context& context, const ast::ExprpostopNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionpostoperator expressionpostoperator{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return expressionpostoperator;
}

}}}