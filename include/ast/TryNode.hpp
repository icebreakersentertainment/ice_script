#ifndef ICE_SCRIPT_TRYNODE_HPP
#define ICE_SCRIPT_TRYNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct StatblockNode;

struct TryNode : LocationInfo
{
    boost::recursive_wrapper<StatblockNode> statblockNode1;
    boost::recursive_wrapper<StatblockNode> statblockNode2;
//    std::string value;
};

}}

#include "ast/StatblockNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::TryNode,
        statblockNode1,
        statblockNode2
//        value
)

#endif //ICE_SCRIPT_TRYNODE_HPP
