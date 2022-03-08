#ifndef ICE_SCRIPT_SCOPENODE_HPP
#define ICE_SCRIPT_SCOPENODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct TypeNode;

struct ScopeNode : LocationInfo
{
    boost::optional<std::string> stuff;
    std::vector<boost::tuple<boost::recursive_wrapper<IdentifierNode>, std::string>> identifierNodes;
    boost::optional<
            boost::tuple<
                boost::recursive_wrapper<IdentifierNode>,
                boost::optional<
                        boost::tuple<
                                boost::recursive_wrapper<TypeNode>,
                                std::vector<boost::recursive_wrapper<TypeNode>>
                        >
                >,
                std::string
            >
    > stuff2;

//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/TypeNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ScopeNode,
        stuff,
        identifierNodes,
        stuff2
//        value
)

#endif //ICE_SCRIPT_SCOPENODE_HPP
