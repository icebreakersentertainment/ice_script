#include "analyzer/detail/analyzers/ExprvalueNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ExprvalueNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionvalue process(logger::ILogger& logger, Context& context, const ast::ExprvalueNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionvalue expressionvalue{};

    ExprvalueNodeVisitor visitor{logger, context};
    expressionvalue.value = boost::apply_visitor(visitor, node.value);

    return expressionvalue;
}

}}}