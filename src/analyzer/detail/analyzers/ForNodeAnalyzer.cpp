#include "analyzer/detail/analyzers/ForNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/ExprstatNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/ForNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::For process(Context& context, const ast::ForNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    For forStatement{};

    ForNodeVisitor visitor{context};
    forStatement.variableOrExpressionstat = boost::apply_visitor(visitor, node.varOrExprstatNode);

    auto booleanType = context.typeTable().get(Type::TypeId::BOOLEAN)[0];

    scope.pushExpectedTypes({booleanType});

    forStatement.expressionstat = process(context, node.exprstatNode.get());

    scope.popExpectedTypes();

    for (const auto& assignNode : node.assignNodes)
    {
        forStatement.assigns.push_back(process(context, assignNode.get()));
    }

    forStatement.statement = process(context, node.statementNode.get());

    return forStatement;
}

}}}