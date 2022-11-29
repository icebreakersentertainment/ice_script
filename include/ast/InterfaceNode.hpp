#ifndef ICE_SCRIPT_INTERFACENODE_HPP
#define ICE_SCRIPT_INTERFACENODE_HPP

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

struct IdentifierNode;
struct VirtpropNode;
struct IntfmthdNode;

struct InterfaceNode : LocationInfo
{
    std::vector<std::string> externalOrShared;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::optional<
            boost::tuple<
                    boost::optional<
                            std::vector<boost::recursive_wrapper<IdentifierNode>>
                    >,
                    std::vector<
                            boost::variant<
                                    monostate,
                                    boost::recursive_wrapper<VirtpropNode>,
                                    boost::recursive_wrapper<IntfmthdNode>
                            >
                    >
            >
    > value;

//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/VirtpropNode.hpp"
#include "ast/IntfmthdNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::InterfaceNode,
        externalOrShared,
        identifierNode,
        value
)

#endif //ICE_SCRIPT_INTERFACENODE_HPP
