#ifndef ICE_SCRIPT_VOIDNODE_HPP
#define ICE_SCRIPT_VOIDNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/Void.hpp"

namespace ice_script { namespace ast {

struct VoidNode : LocationInfo
{
    Void value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::VoidNode,
        value
)

#endif //ICE_SCRIPT_VOIDNODE_HPP
