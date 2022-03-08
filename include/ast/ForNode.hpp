#ifndef ICE_SCRIPT_FORNODE_HPP
#define ICE_SCRIPT_FORNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct VarNode;
struct ExprstatNode;
struct AssignNode;
struct StatementNode;

struct ForNode : LocationInfo
{
    boost::variant<boost::recursive_wrapper<VarNode>, boost::recursive_wrapper<ExprstatNode>>  varOrExprstatNode;
    boost::recursive_wrapper<ExprstatNode> exprstatNode;
    std::vector<boost::recursive_wrapper<AssignNode>> assignNodes;
    std::vector<boost::recursive_wrapper<StatementNode>> statementNode;

//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ForNode,
        varOrExprstatNode,
        exprstatNode,
        assignNodes,
        statementNode
//        value
)

#endif //ICE_SCRIPT_FORNODE_HPP
