#ifndef ICE_SCRIPT_BITOPNODE_HPP
#define ICE_SCRIPT_BITOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/BitwiseOperator.hpp"

namespace ice_script { namespace ast {

struct BitopNode : LocationInfo
{
    BitwiseOperator bitwiseOperator;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::BitopNode,
        bitwiseOperator
)

#endif //ICE_SCRIPT_BITOPNODE_HPP
