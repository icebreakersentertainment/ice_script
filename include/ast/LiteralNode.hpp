#ifndef ICE_SCRIPT_LITERALNODE_HPP
#define ICE_SCRIPT_LITERALNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/StringNode.hpp"
#include "ast/BoolNode.hpp"
#include "ast/NullNode.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct NumberNode;
//struct StringNode;
struct BitsNode;

struct LiteralNode : LocationInfo
{
    boost::variant<monostate, boost::recursive_wrapper<NumberNode>, StringNode, boost::recursive_wrapper<ast::BitsNode>, BoolNode, NullNode> value;
//    std::string value;
};

}}

#include "ast/NumberNode.hpp"
//#include "ast/StringNode.hpp"
#include "ast/BitsNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::LiteralNode,
        value
)

#endif //ICE_SCRIPT_LITERALNODE_HPP
