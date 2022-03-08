#ifndef ICE_SCRIPT_NUMBERNODE_HPP
#define ICE_SCRIPT_NUMBERNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct NumberNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::NumberNode,
        value
)

#endif //ICE_SCRIPT_NUMBERNODE_HPP
