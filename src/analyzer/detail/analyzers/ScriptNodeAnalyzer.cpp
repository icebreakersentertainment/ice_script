#include "analyzer/detail/analyzers/ScriptNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Script process(Context& context, const ast::ScriptNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Script script{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return script;
}

}}}