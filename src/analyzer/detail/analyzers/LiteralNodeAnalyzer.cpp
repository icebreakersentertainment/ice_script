#include "analyzer/detail/analyzers/LiteralNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/LiteralNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Literal process(logger::ILogger& logger, Context& context, const ast::LiteralNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Literal literal{};

    LiteralNodeVisitor visitor{logger, context};
    literal.value = boost::apply_visitor(visitor, node.value);

    return literal;
}

}}}