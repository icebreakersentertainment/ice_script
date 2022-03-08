#ifndef ICE_SCRIPT_EXPRPREOPNODE_HPP
#define ICE_SCRIPT_EXPRPREOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ExprpreopNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprpreopNode,
        value
)

#endif //ICE_SCRIPT_EXPRPREOPNODE_HPP
