#include "analyzer/detail/analyzers/NamespaceNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Namespace process(Context& context, const ast::NamespaceNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Namespace namespaceDefinition{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return namespaceDefinition;
}

}}}