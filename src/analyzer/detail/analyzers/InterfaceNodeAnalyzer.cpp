#include "analyzer/detail/analyzers/InterfaceNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Interface process(Context& context, const ast::InterfaceNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Interface interfaceData{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return interfaceData;
}

}}}