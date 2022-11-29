#ifndef ICE_SCRIPT_FUNCNODE_HPP
#define ICE_SCRIPT_FUNCNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct IdentifierNode;
struct ParamlistNode;
struct FuncattrNode;
struct StatblockNode;

using TupleTypeOptionalStringType = boost::tuple<boost::recursive_wrapper<TypeNode>, boost::optional<std::string>>;

struct FuncNode : LocationInfo
{
    std::vector<std::string> externalOrShared;
    boost::optional<std::string> privateOrProtected;
    boost::optional<
            boost::variant<
                    monostate,
                    TupleTypeOptionalStringType,
                    std::string
            >
    > value1;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::recursive_wrapper<ParamlistNode> paramlistNode;
    bool constant;
    boost::recursive_wrapper<FuncattrNode> funcattrNode;
    boost::optional<boost::recursive_wrapper<StatblockNode>> optionalStatblockNode;

//     std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ParamlistNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/StatblockNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::FuncNode,
        externalOrShared,
        privateOrProtected,
        value1,
        identifierNode,
        paramlistNode,
        constant,
        funcattrNode,
        optionalStatblockNode
//        value
)

#endif //ICE_SCRIPT_FUNCNODE_HPP
