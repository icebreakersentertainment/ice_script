#include "analyzer/detail/analyzers/TypemodNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

Typemodifier process(Context& context, const ast::TypemodNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Typemodifier typemodifier{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return typemodifier;
}

}}}