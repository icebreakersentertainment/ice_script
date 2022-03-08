#ifndef ICE_SCRIPT_MIXINNODE_HPP
#define ICE_SCRIPT_MIXINNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ClassNode;

struct MixinNode : LocationInfo
{
    boost::recursive_wrapper<ClassNode> value;
//    std::string value;
};

}}

#include "ast/ClassNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::MixinNode,
        value
)

#endif //ICE_SCRIPT_MIXINNODE_HPP
