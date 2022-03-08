#ifndef ICE_SCRIPT_BOOLNODE_HPP
#define ICE_SCRIPT_BOOLNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/Boolean.hpp"

namespace ice_script { namespace ast {

struct BoolNode : LocationInfo
{
    Boolean value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::BoolNode,
        value
)

#endif //ICE_SCRIPT_BOOLNODE_HPP
