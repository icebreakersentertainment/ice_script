#ifndef ICE_SCRIPT_RETURNNODE_HPP
#define ICE_SCRIPT_RETURNNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct AssignNode;

struct ReturnNode : LocationInfo
{
    boost::optional<boost::recursive_wrapper<AssignNode>> value;
//    std::string value;
};

}}

#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ReturnNode,
        value
)

#endif //ICE_SCRIPT_RETURNNODE_HPP
