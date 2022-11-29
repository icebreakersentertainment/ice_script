#include "analyzer/detail/analyzers/TypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

Type process(Context& context, const ast::TypeNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Type type{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return type;
}

}}}