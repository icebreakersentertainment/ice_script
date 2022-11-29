#ifndef ICE_SCRIPT_ARGLISTNODE_HPP
#define ICE_SCRIPT_ARGLISTNODE_HPP

#include "ast/ArglistNode.hpp"
#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct AssignNode;

struct ArglistArgument
{
    boost::optional<boost::recursive_wrapper<IdentifierNode>> identifier;
    boost::recursive_wrapper<AssignNode> assignNode;
};

using ArglistArgumentsType = std::vector<ArglistArgument>;

struct ArglistNode : LocationInfo
{
    ArglistNode() = default;

    explicit ArglistNode(ArglistArgumentsType value) : value(std::move(value))
    {

    }

    // arglistRule = -(identifierRule >>  string(":")) >> assignRule >> *(lit(",") >> -(identifierRule >> string(":")) >> assignRule);
//    boost::optional<boost::tuple<boost::recursive_wrapper<IdentifierNode>, std::string>> identifierNode1;
//    boost::recursive_wrapper<AssignNode> assignNode1;
//    std::vector<
//            boost::tuple<
//                    boost::optional<
//                            boost::tuple<
//                                    boost::recursive_wrapper<IdentifierNode>,
//                                    std::string
//                            >
//                    >,
//                    boost::recursive_wrapper<AssignNode>
//            >
//    > value;
    ArglistArgumentsType value;
//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/AssignNode.hpp"

//BOOST_FUSION_ADAPT_STRUCT(
//        ice_script::ast::ArglistNode,
////        identifierNode1,
////        assignNode1,
////        identifierNodeAssignNode2
//        value
//)

BOOST_FUSION_ADAPT_STRUCT(
       ice_script::ast::ArglistArgument,
//        identifierNode1,
//        assignNode1,
//        identifierNodeAssignNode2
       identifier,
       assignNode
)

#endif //ICE_SCRIPT_ARGLISTNODE_HPP
