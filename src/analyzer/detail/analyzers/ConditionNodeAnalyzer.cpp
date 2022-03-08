#include "analyzer/detail/analyzers/ConditionNodeAnalyzer.hpp"

#include "analyzer/detail/analyzers/ExprNodeAnalyzer.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

asg::Condition process(logger::ILogger& logger, Context& context, const ast::ConditionNode& node)
{
    LOG_DEBUG((&logger), "Analyzing %s", typeid(node).name())

    Scope& scope = context.scope();

//    boost::recursive_wrapper<ExprNode> exprNode;
//    boost::optional<
//            boost::tuple<boost::recursive_wrapper<AssignNode>, boost::recursive_wrapper<AssignNode>>
//    > assignNode;

    Condition condition{};

    condition.expression = process(logger, context, node.exprNode.get());

//    if (node.assignNode)
//    {
//        Assign assign1 = process(logger, context, boost::get<0>(node.assignNode.get()).get());
//        Assign assign2 = process(logger, context, boost::get<1>(node.assignNode.get()).get());
//
//        condition.assign = {{assign1, assign2}};
//    }

    return condition;
}

}}}