#include "analyzer/detail/analyzers/MixinNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Mixin process(logger::ILogger& logger, Context& context, const ast::MixinNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Mixin mixin{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return mixin;
}

}}}