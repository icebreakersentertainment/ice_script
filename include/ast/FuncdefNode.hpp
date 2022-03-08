#ifndef ICE_SCRIPT_FUNCDEFNODE_HPP
#define ICE_SCRIPT_FUNCDEFNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct IdentifierNode;
struct ParamlistNode;

struct FuncdefNode : LocationInfo
{
    std::vector<std::string> externalOrShared;
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::optional<std::string> isRef;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ParamlistNode> paramlistNode;

//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ParamlistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::FuncdefNode,
        externalOrShared,
        typeNode,
        isRef,
        identifierNode,
        paramlistNode
//        value
)

#endif //ICE_SCRIPT_FUNCDEFNODE_HPP
