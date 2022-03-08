#ifndef ICE_SCRIPT_CASTNODE_HPP
#define ICE_SCRIPT_CASTNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct AssignNode;

struct CastNode : LocationInfo
{
    // typeRule >> string(">") >> string("(") >> assignRule >> string(")");
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::recursive_wrapper<AssignNode> assignNode;
//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::CastNode,
        typeNode,
        assignNode
//        value
)

#endif //ICE_SCRIPT_CASTNODE_HPP
