#ifndef ICE_SCRIPT_BITSNODE_HPP
#define ICE_SCRIPT_BITSNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct BitsNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::BitsNode,
        value
)

#endif //ICE_SCRIPT_BITSNODE_HPP
