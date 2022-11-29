#include "analyzer/detail/analyzers/ExprpostopNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ExprpostopNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Expressionpostoperator process(Context& context, const ast::ExprpostopNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Expressionpostoperator expressionpostoperator{};

    ExprpostopNodeVisitor visitor{context};
    expressionpostoperator.value = boost::apply_visitor(visitor, node.value);

    return expressionpostoperator;
}

}}}