#ifndef ICE_SCRIPT_NAMESPACENODE_HPP
#define ICE_SCRIPT_NAMESPACENODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct ScriptNode;

struct NamespaceNode : LocationInfo
{
    std::string _namespace;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    std::vector<boost::recursive_wrapper<IdentifierNode>> identifierNodes;
    boost::recursive_wrapper<ScriptNode> scriptNode;

//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/ScriptNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::NamespaceNode,
        _namespace,
        identifierNode,
        identifierNodes,
        scriptNode
//        value
)

#endif //ICE_SCRIPT_NAMESPACENODE_HPP
