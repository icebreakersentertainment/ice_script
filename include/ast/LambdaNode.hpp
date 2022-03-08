#ifndef ICE_SCRIPT_LAMBDANODE_HPP
#define ICE_SCRIPT_LAMBDANODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct TypemodNode;
struct IdentifierNode;
struct StatblockNode;

struct LambdaNode : LocationInfo
{
    // -(-(typeRule >> typemodRule) >> identifierRule >> *(lit(",") >> -(typeRule >> typemodRule) >> identifierRule)) >> lit(")" >> statblockRule;
    boost::optional<
            boost::tuple<
                    boost::optional<
                            boost::tuple<boost::recursive_wrapper<TypeNode>, boost::recursive_wrapper<TypemodNode>>
                    >,
                    boost::recursive_wrapper<IdentifierNode>,
                    std::vector<
                            boost::tuple<
                                    boost::optional<
                                            boost::tuple<boost::recursive_wrapper<TypeNode>, boost::recursive_wrapper<TypemodNode>>
                                    >,
                                    boost::recursive_wrapper<IdentifierNode>
                            >
                    >
            >
    > typeNodeStuff;
    boost::recursive_wrapper<StatblockNode> statblockNode;
//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/TypemodNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/StatblockNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::LambdaNode,
        typeNodeStuff,
        statblockNode
//        value
)

#endif //ICE_SCRIPT_LAMBDANODE_HPP
