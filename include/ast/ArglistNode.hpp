#ifndef ICE_SCRIPT_ARGLISTNODE_HPP
#define ICE_SCRIPT_ARGLISTNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct AssignNode;

struct ArglistNode : LocationInfo
{
    // arglistRule = -(identifierRule >>  string(":")) >> assignRule >> *(lit(",") >> -(identifierRule >> string(":")) >> assignRule);
//    boost::optional<boost::tuple<boost::recursive_wrapper<IdentifierNode>, std::string>> identifierNode1;
//    boost::recursive_wrapper<AssignNode> assignNode1;
    std::vector<
            boost::tuple<
                    boost::optional<
                            boost::tuple<
                                    boost::recursive_wrapper<IdentifierNode>,
                                    std::string
                            >
                    >,
                    boost::recursive_wrapper<AssignNode>
            >
    > value;
//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ArglistNode,
//        identifierNode1,
//        assignNode1,
//        identifierNodeAssignNode2
        value
)

#endif //ICE_SCRIPT_ARGLISTNODE_HPP
