#ifndef ICE_SCRIPT_STRINGNODE_HPP
#define ICE_SCRIPT_STRINGNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct StringNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::StringNode,
        value
)

#endif //ICE_SCRIPT_STRINGNODE_HPP
