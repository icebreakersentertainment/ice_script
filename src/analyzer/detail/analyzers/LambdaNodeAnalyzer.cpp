#include "analyzer/detail/analyzers/LambdaNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Lambda process(Context& context, const ast::LambdaNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Lambda lambda{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return lambda;
}

}}}