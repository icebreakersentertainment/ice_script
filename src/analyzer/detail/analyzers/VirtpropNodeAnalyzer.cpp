#include "analyzer/detail/analyzers/VirtpropNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Virtualproperatorerty process(logger::ILogger& logger, Context& context, const ast::VirtpropNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Virtualproperatorerty virtualproperatorerty{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return virtualproperatorerty;
}

}}}