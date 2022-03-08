#ifndef ICE_SCRIPT_CASENODE_HPP
#define ICE_SCRIPT_CASENODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ExprNode;
struct StatementNode;

struct CaseNode : LocationInfo
{
    boost::variant<
            boost::tuple<std::string, boost::recursive_wrapper<ExprNode>>,
            std::string
    > type;
    std::vector<boost::recursive_wrapper<StatementNode>> statementNodes;
//    std::string value;
};

}}

#include "ast/ExprNode.hpp"
#include "ast/StatementNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::CaseNode,
        type,
        statementNodes
//        value
)

#endif //ICE_SCRIPT_CASENODE_HPP
