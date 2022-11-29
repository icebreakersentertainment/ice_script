#include "analyzer/detail/analyzers/InitlistNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Initlist process(Context& context, const ast::InitlistNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Initlist initlist{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return initlist;
}

}}}