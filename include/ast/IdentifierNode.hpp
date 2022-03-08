#ifndef ICE_SCRIPT_IDENTIFIERNODE_HPP
#define ICE_SCRIPT_IDENTIFIERNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::IdentifierNode,
        value
)

#endif //ICE_SCRIPT_IDENTIFIERNODE_HPP
