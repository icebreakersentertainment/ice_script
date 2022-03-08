#ifndef ICE_SCRIPT_TYPEMODNODE_HPP
#define ICE_SCRIPT_TYPEMODNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/fusion/include/boost_tuple.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct TypemodNode : LocationInfo
{
    boost::optional<
            boost::tuple<
                    std::string,
                    boost::optional<std::string>
            >
    > value;

//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::TypemodNode,
        value
)

#endif //ICE_SCRIPT_TYPEMODNODE_HPP
