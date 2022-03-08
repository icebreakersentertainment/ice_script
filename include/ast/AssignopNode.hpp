#ifndef ICE_SCRIPT_ASSIGNOPNODE_HPP
#define ICE_SCRIPT_ASSIGNOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct AssignopNode : LocationInfo
{
    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::AssignopNode,
        value
)

#endif //ICE_SCRIPT_ASSIGNOPNODE_HPP
