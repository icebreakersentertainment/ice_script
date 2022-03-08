#ifndef ICE_SCRIPT_FUNCCALLNODE_HPP
#define ICE_SCRIPT_FUNCCALLNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ScopeNode;
struct IdentifierNode;
struct ArglistNode;

struct FunccallNode : LocationInfo
{
    // funccallRule = qi::eps >> scopeRule >> identifierRule >> arglistRule;
    boost::recursive_wrapper<ScopeNode> scopeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ArglistNode> arglistNode;
//    std::string value;
};

}}

#include "ast/ScopeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ArglistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::FunccallNode,
        scopeNode,
        identifierNode,
        arglistNode
//        value
)

#endif //ICE_SCRIPT_FUNCCALLNODE_HPP
