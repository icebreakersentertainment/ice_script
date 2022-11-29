#include "analyzer/detail/analyzers/LiteralNodeAnalyzer.hpp"

#include "analyzer/detail/visitors/LiteralNodeVisitor.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Literal process(Context& context, const ast::LiteralNode& node)
{
    LOG_DEBUG((&context.logger()), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

    Literal literal{};

    LiteralNodeVisitor visitor{context};
    literal.value = boost::apply_visitor(visitor, node.value);

    return literal;
}

}}}