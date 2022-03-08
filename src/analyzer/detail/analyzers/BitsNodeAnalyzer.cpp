#include "analyzer/detail/analyzers/BitsNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Bits process(logger::ILogger& logger, Context& context, const ast::BitsNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Bits bits{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return bits;
}

}}}