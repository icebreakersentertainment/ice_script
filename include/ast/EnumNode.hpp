#ifndef ICE_SCRIPT_ENUMNODE_HPP
#define ICE_SCRIPT_ENUMNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct ExprNode;

struct EnumNode : LocationInfo
{
    std::vector<std::string> externalOrShared;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::optional<
            std::vector<
                    boost::tuple<
                            boost::recursive_wrapper<IdentifierNode>,
                            boost::optional<boost::recursive_wrapper<ExprNode>>
                    >
            >
    > value;

//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/ExprNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::EnumNode,
        externalOrShared,
        identifierNode,
        value
)

#endif //ICE_SCRIPT_ENUMNODE_HPP
