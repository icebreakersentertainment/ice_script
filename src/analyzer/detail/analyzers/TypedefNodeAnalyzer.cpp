#include "analyzer/detail/analyzers/TypedefNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

Typedefinition process(Context& context, const ast::TypedefNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Typedefinition typedefinition{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return typedefinition;
}

}}}