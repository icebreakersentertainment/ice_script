#ifndef ICE_SCRIPT_EXPRPOSTOPNODE_HPP
#define ICE_SCRIPT_EXPRPOSTOPNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"
#include "ast/PostfixOperator.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct FunccallNode;
struct IdentifierNode;
struct AssignNode;
struct ArglistNode;

using FunccallOrIdentifierType = boost::variant<monostate, boost::recursive_wrapper<FunccallNode>, boost::recursive_wrapper<IdentifierNode>>;

// using OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType = boost::tuple<
//         boost::optional<boost::recursive_wrapper<IdentifierNode>>,
//         boost::recursive_wrapper<AssignNode>,
//         std::vector<
//                 boost::tuple<
//                         boost::optional<boost::recursive_wrapper<IdentifierNode>>,
//                         boost::recursive_wrapper<AssignNode>
//                 >
//         >
// >;

struct ExprpostopNode : LocationInfo
{
    boost::variant<
            monostate,
            FunccallOrIdentifierType,
        //     OptionalIdentifierAssignVectorTupleOptionalIdentifierAssignType,
            boost::recursive_wrapper<AssignNode>,
            boost::recursive_wrapper<ArglistNode>,
            PostfixOperator

    > value;
//    std::string value;
};

}}

#include "ast/FunccallNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/AssignNode.hpp"
#include "ast/ArglistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprpostopNode,
        value
)

#endif //ICE_SCRIPT_EXPRPOSTOPNODE_HPP
