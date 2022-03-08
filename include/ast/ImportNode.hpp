#ifndef ICE_SCRIPT_IMPORTNODE_HPP
#define ICE_SCRIPT_IMPORTNODE_HPP

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
struct FuncattrNode;
struct StringNode;

struct ImportNode : LocationInfo
{
    std::string value;
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::optional<std::string> isRef;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ParamlistNode> paramlistNode;
    boost::recursive_wrapper<FuncattrNode> funcattrNode;
    boost::recursive_wrapper<StringNode> stringNode;

//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ParamlistNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/StringNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ImportNode,
        value,
        typeNode,
        isRef,
        identifierNode,
        paramlistNode
//        funcattrNode,
//        stringNode
//        value
)

#endif //ICE_SCRIPT_IMPORTNODE_HPP
