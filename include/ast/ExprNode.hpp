#ifndef ICE_SCRIPT_EXPRNODE_HPP
#define ICE_SCRIPT_EXPRNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ExprtermNode;
struct ExpropNode;

struct ExpropNodeAndExprtermNode
{
    boost::recursive_wrapper<ExpropNode> expropNode;
    boost::recursive_wrapper<ExprtermNode> exprtermNode;
};

struct ExprNode : LocationInfo
{
    boost::recursive_wrapper<ExprtermNode> exprtermNode;
//    std::vector<boost::tuple<boost::recursive_wrapper<ExpropNode>, boost::recursive_wrapper<ExprtermNode>>> value;
    std::vector<ExpropNodeAndExprtermNode> expropNodeAndExprtermNodes;
//    std::string value;
};

}}

#include "ast/ExprtermNode.hpp"
#include "ast/ExpropNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExpropNodeAndExprtermNode,
        expropNode,
        exprtermNode
)

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprNode,
        exprtermNode,
        expropNodeAndExprtermNodes
)

#endif //ICE_SCRIPT_EXPRNODE_HPP
