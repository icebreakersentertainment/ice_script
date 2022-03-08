#ifndef ICE_SCRIPT_PRIMTYPENODE_HPP
#define ICE_SCRIPT_PRIMTYPENODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/PrimitiveType.hpp"

namespace ice_script { namespace ast {

struct PrimtypeNode : LocationInfo
{
    PrimitiveType primitiveType;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::PrimtypeNode,
        primitiveType
)

#endif //ICE_SCRIPT_PRIMTYPENODE_HPP
