#include "analyzer/detail/analyzers/PrimtypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Primativetype process(Context& context, const ast::PrimtypeNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Primativetype primativetype{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return primativetype;
}

}}}