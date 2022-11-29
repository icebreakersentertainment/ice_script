#ifndef ICE_SCRIPT_EXPRTERMNODE_HPP
#define ICE_SCRIPT_EXPRTERMNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct LocationInfo;
struct TypeNode;
struct InitlistNode;
struct ExprpreopNode;
struct ExprvalueNode;
struct ExprpostopNode;

struct ExprpreopsExprvalueExprpostops
{
    std::vector<boost::recursive_wrapper<ExprpreopNode>> exprPreopNodes;
    boost::recursive_wrapper<ExprvalueNode> exprValueNode;
    std::vector<boost::recursive_wrapper<ExprpostopNode>> exprPostopNodes;
};

using OptionalTypeAndInitListType = boost::tuple<boost::optional<boost::recursive_wrapper<TypeNode>>, boost::recursive_wrapper<InitlistNode>>;
//using VectorExprpreopExprvalueVectorExprpreopType = boost::tuple<
//        std::vector<boost::recursive_wrapper<ExprpreopNode>>,
//        boost::recursive_wrapper<ExprvalueNode>,
//        std::vector<boost::recursive_wrapper<ExprpostopNode>>
//>;

struct ExprtermNode : LocationInfo
{
    boost::variant<
            monostate,
            OptionalTypeAndInitListType,
            ExprpreopsExprvalueExprpostops
    > value;
//    std::string value;
};

}}

#include "ast/LocationInfo.hpp"
#include "ast/TypeNode.hpp"
#include "ast/InitlistNode.hpp"
#include "ast/ExprpreopNode.hpp"
#include "ast/ExprvalueNode.hpp"
#include "ast/ExprpostopNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprpreopsExprvalueExprpostops,
        exprPreopNodes,
        exprValueNode,
        exprPostopNodes
)

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprtermNode,
        value
)

#endif //ICE_SCRIPT_EXPRTERMNODE_HPP
