#ifndef ICE_SCRIPT_VIRTPROPNODE_HPP
#define ICE_SCRIPT_VIRTPROPNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct IdentifierNode;
struct FuncattrNode;
struct StatblockNode;

struct VirtpropNode : LocationInfo
{
    boost::optional<std::string> isPrivateOrProtected;
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::optional<std::string> isRef;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    std::vector<
            boost::tuple<
                    std::string,
                    boost::optional<std::string>,
                    boost::recursive_wrapper<FuncattrNode>,
                    boost::variant<boost::recursive_wrapper<StatblockNode>, std::string>
            >
    > stuff;

//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/StatblockNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::VirtpropNode,
        isPrivateOrProtected,
        typeNode,
        isRef,
        identifierNode,
        stuff
//        value
)

#endif //ICE_SCRIPT_VIRTPROPNODE_HPP
