#include "analyzer/detail/analyzers/StringNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::String process(logger::ILogger& logger, Context& context, const ast::StringNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    String string{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return string;
}

}}}