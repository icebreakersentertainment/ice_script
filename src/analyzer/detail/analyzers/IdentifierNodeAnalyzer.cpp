#include "analyzer/detail/analyzers/IdentifierNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Identifier process(logger::ILogger& logger, Context& context, const ast::IdentifierNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Identifier identifier{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return identifier;
}

}}}