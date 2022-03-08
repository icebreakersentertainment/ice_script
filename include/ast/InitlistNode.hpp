#ifndef ICE_SCRIPT_INITLISTNODE_HPP
#define ICE_SCRIPT_INITLISTNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct InitlistNode;
struct AssignNode;

struct InitlistNode : LocationInfo
{
    std::vector<
            boost::variant<
                    boost::recursive_wrapper<AssignNode>,
                    boost::recursive_wrapper<InitlistNode>
            >
    > value;

//    std::string value;
};

}}

#include "ast/InitlistNode.hpp"
#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::InitlistNode,
        value
)

#endif //ICE_SCRIPT_INITLISTNODE_HPP
