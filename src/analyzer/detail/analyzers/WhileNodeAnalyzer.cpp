#include "analyzer/detail/analyzers/WhileNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::While process(logger::ILogger& logger, Context& context, const ast::WhileNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    While whileStatement{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return whileStatement;
}

}}}