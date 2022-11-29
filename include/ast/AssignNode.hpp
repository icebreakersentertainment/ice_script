#ifndef ICE_SCRIPT_ASSIGNNODE_HPP
#define ICE_SCRIPT_ASSIGNNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ConditionNode;
struct AssignNode;
struct AssignopNode;

struct AssignopAssignNode
{
    boost::recursive_wrapper<AssignopNode> assignopNode;
    boost::recursive_wrapper<AssignNode> assignNode;
};

struct AssignNode : LocationInfo
{
    // assignRule = qi::eps >> conditionRule >> -(assignopRule >> assignRule);
    boost::recursive_wrapper<ConditionNode> conditionNode;
    boost::optional<AssignopAssignNode> assignopAssignNode;
//    std::string value;
};

}}

#include "ast/ConditionNode.hpp"
#include "ast/AssignopNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::AssignopAssignNode,
        assignopNode,
        assignNode
)

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::AssignNode,
        conditionNode,
        assignopAssignNode
)

#endif //ICE_SCRIPT_ASSIGNNODE_HPP
