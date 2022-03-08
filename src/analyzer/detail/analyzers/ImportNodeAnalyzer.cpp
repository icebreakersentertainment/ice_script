#include "analyzer/detail/analyzers/ImportNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Import process(logger::ILogger& logger, Context& context, const ast::ImportNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Import import{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return import;
}

}}}