#ifndef ICE_SCRIPT_TYPEDEFNODE_HPP
#define ICE_SCRIPT_TYPEDEFNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct PrimtypeNode;
struct IdentifierNode;

struct TypedefNode : LocationInfo
{
    // TYPEDEF       ::= 'typedef' PRIMTYPE IDENTIFIER ';'
    boost::recursive_wrapper<PrimtypeNode> primTypeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    std::string value;
};

}}

#include "ast/PrimtypeNode.hpp"
#include "ast/IdentifierNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::TypedefNode,
        primTypeNode,
        identifierNode
//        value
)

#endif //ICE_SCRIPT_TYPEDEFNODE_HPP
