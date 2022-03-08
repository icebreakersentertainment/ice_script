#ifndef ICE_SCRIPT_NULLNODE_HPP
#define ICE_SCRIPT_NULLNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/Null.hpp"

namespace ice_script { namespace ast {

struct NullNode : LocationInfo
{
    Null value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::NullNode,
        value
)

#endif //ICE_SCRIPT_NULLNODE_HPP
