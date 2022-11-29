#ifndef ICE_SCRIPT_ASSIGNOPNODE_HPP
#define ICE_SCRIPT_ASSIGNOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/AssignOperator.hpp"

namespace ice_script { namespace ast {

struct AssignopNode : LocationInfo
{
    AssignOperator assignOperator;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::AssignopNode,
        assignOperator
)

#endif //ICE_SCRIPT_ASSIGNOPNODE_HPP
