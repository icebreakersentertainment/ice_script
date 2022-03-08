#ifndef ICE_SCRIPT_INTFMTHDNODE_HPP
#define ICE_SCRIPT_INTFMTHDNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct IdentifierNode;
struct ParamlistNode;

struct IntfmthdNode : LocationInfo
{
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::optional<std::string> isRef;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ParamlistNode> paramlistNode;
    boost::optional<std::string> isConst;

//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ParamlistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::IntfmthdNode,
        typeNode,
        isRef,
        identifierNode,
        paramlistNode,
        isConst
//        value
)

#endif //ICE_SCRIPT_INTFMTHDNODE_HPP
