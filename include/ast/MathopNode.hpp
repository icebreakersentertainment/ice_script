#ifndef ICE_SCRIPT_MATHOPNODE_HPP
#define ICE_SCRIPT_MATHOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/MathOperator.hpp"

namespace ice_script { namespace ast {

struct MathopNode : LocationInfo
{
    MathOperator mathOperator;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::MathopNode,
        mathOperator
)

#endif //ICE_SCRIPT_MATHOPNODE_HPP
