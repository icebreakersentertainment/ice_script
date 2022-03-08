#include "analyzer/detail/analyzers/ExpropNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ExpropNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionoperatorerty process(logger::ILogger& logger, Context& context, const ast::ExpropNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionoperatorerty expressionoperatorerty{};

    ExpropNodeVisitor visitor{logger, context};
    expressionoperatorerty.value = boost::apply_visitor(visitor, node.value);

    return expressionoperatorerty;
}

}}}