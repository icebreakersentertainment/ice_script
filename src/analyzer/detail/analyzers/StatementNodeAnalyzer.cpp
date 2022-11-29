#include "analyzer/detail/analyzers/StatementNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/StatementNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Statement process(Context& context, const ast::StatementNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Statement statement{};

    StatementNodeVisitor visitor{context};
    statement.value = boost::apply_visitor(visitor, node.value);

    return statement;
}

}}}