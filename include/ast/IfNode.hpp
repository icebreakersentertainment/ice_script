#ifndef ICE_SCRIPT_IFNODE_HPP
#define ICE_SCRIPT_IFNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct AssignNode;
struct StatementNode;

struct IfNode : LocationInfo
{
    boost::recursive_wrapper<AssignNode> assignNode;
    boost::recursive_wrapper<StatementNode> statementNode;
    boost::optional<boost::recursive_wrapper<StatementNode>> optionalStatementNode;
//    std::string value;
};

}}

#include "ast/AssignNode.hpp"
#include "ast/StatementNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::IfNode,
        assignNode,
        statementNode,
        optionalStatementNode
//        value
)

#endif //ICE_SCRIPT_IFNODE_HPP
