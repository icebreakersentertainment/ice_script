#include "analyzer/detail/analyzers/EnumNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Enumeration process(logger::ILogger& logger, Context& context, const ast::EnumNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Enumeration enumeration{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return enumeration;
}

}}}