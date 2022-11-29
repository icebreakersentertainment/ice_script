#include "analyzer/detail/analyzers/DowhileNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Dowhile process(Context& context, const ast::DowhileNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Dowhile dowhile{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return dowhile;
}

}}}