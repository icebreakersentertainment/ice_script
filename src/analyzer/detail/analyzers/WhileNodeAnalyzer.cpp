#include "analyzer/detail/analyzers/WhileNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/AssignNodeAnalyzer.hpp"
#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::While process(Context& context, const ast::WhileNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    While whileStatement{};

    auto booleanType = context.typeTable().get(Type::TypeId::BOOLEAN)[0];

    scope.pushExpectedTypes({booleanType});

    whileStatement.assign = process(context, node.assignNode.get());

    scope.popExpectedTypes();

    whileStatement.statement = process(context, node.statementNode.get());
    
    return whileStatement;
}

}}}