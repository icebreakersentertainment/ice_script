#ifndef ICE_SCRIPT_VARNODE_HPP
#define ICE_SCRIPT_VARNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/optional/optional.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"
#include "ast/Visibility.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct IdentifierNode;
struct InitlistNode;
struct ExprNode;
struct ArglistNode;

using InitListOrExprOrArgListType = boost::variant<
        monostate,
        boost::variant<
                monostate,
                boost::recursive_wrapper<InitlistNode>,
                boost::recursive_wrapper<ExprNode>
        >,
        boost::recursive_wrapper<ArglistNode>
>;

struct VarNode : LocationInfo
{
    boost::optional<Visibility> visibility;
    boost::recursive_wrapper<TypeNode> typeNode;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
    boost::optional<InitListOrExprOrArgListType> initListOrExprOrArgList;
    std::vector<
            boost::tuple<
                    boost::recursive_wrapper<IdentifierNode>,
                    boost::optional<InitListOrExprOrArgListType>
            >
    > stuff;

//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/InitlistNode.hpp"
#include "ast/ExprNode.hpp"
#include "ast/ArglistNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::VarNode,
        visibility,
        typeNode,
        identifierNode,
        initListOrExprOrArgList,
        stuff
//        value
)

#endif //ICE_SCRIPT_VARNODE_HPP
