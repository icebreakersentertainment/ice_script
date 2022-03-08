#include "analyzer/detail/analyzers/DatatypeNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Datatype process(logger::ILogger& logger, Context& context, const ast::DatatypeNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Datatype datatype{};

//    expression.expressionterm = boost::get<Expressionterm>(operator()(node.exprtermNode));

    return datatype;
}

}}}