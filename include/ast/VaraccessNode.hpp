#ifndef ICE_SCRIPT_VARACCESSNODE_HPP
#define ICE_SCRIPT_VARACCESSNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ScopeNode;
struct IdentifierNode;

struct VaraccessNode : LocationInfo
{
    // varaccessRule = qi::eps >> scopeRule >> identifierRule;
    boost::recursive_wrapper<ScopeNode> scopeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    std::string value;
};

}}

#include "ast/ScopeNode.hpp"
#include "ast/IdentifierNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::VaraccessNode,
        scopeNode,
        identifierNode
//        value
)

#endif //ICE_SCRIPT_VARACCESSNODE_HPP
