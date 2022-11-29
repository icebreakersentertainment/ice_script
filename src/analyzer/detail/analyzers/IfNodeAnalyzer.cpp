#include "analyzer/detail/analyzers/IfNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::If process(Context& context, const ast::IfNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    If ifStatement{};

    auto booleanType = context.typeTable().get(Type::TypeId::BOOLEAN)[0];

    scope.pushExpectedTypes({booleanType});

    ifStatement.assign = process(context, node.assignNode.get());

    scope.popExpectedTypes();

    ifStatement.statement = process(context, node.statementNode.get());

    if (node.optionalStatementNode)
    {
        ifStatement.optionalStatement = {process(context, node.optionalStatementNode.get().get())};
    }

    return ifStatement;
}

}}}