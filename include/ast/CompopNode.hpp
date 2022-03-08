#ifndef ICE_SCRIPT_COMPOPNODE_HPP
#define ICE_SCRIPT_COMPOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/ComparisonOperator.hpp"

namespace ice_script { namespace ast {

struct CompopNode : LocationInfo
{
    ComparisonOperator comparisonOperator;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::CompopNode,
        comparisonOperator
)

#endif //ICE_SCRIPT_COMPOPNODE_HPP
