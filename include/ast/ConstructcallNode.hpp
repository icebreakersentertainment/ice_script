#ifndef ICE_SCRIPT_CONSTRUCTCALLNODE_HPP
#define ICE_SCRIPT_CONSTRUCTCALLNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct ArglistNode;

struct ConstructcallNode : LocationInfo
{
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::recursive_wrapper<ArglistNode> arglistNode;
//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/ArglistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ConstructcallNode,
        typeNode,
        arglistNode
//        value
)

#endif //ICE_SCRIPT_CONSTRUCTCALLNODE_HPP
