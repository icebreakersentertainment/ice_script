#ifndef ICE_SCRIPT_CONDITIONNODE_HPP
#define ICE_SCRIPT_CONDITIONNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ExprNode;
struct AssignNode;

struct ConditionNode : LocationInfo
{
    // conditionRule = qi::eps >> exprRule >> -(string("?") >> assignRule >> string(":") >> assignRule);
    boost::recursive_wrapper<ExprNode> exprNode;
    boost::optional<
            boost::tuple<boost::recursive_wrapper<AssignNode>, boost::recursive_wrapper<AssignNode>>
    > assignNode;
//    std::string value;
};

}}

#include "ast/ExprNode.hpp"
#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ConditionNode,
        exprNode,
        assignNode
//        value
)

#endif //ICE_SCRIPT_CONDITIONNODE_HPP
