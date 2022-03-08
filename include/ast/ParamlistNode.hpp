#ifndef ICE_SCRIPT_PARAMLISTNODE_HPP
#define ICE_SCRIPT_PARAMLISTNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

#include "ast/TypeNode.hpp"
#include "ast/TypemodNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ExprNode.hpp"

namespace ice_script { namespace ast {

struct TypeNode;
struct TypemodNode;
struct IdentifierNode;
struct ExprNode;

using TypeTypeModIdentifierExprType = boost::tuple<
        boost::recursive_wrapper<TypeNode>,
        boost::recursive_wrapper<TypemodNode>,
        boost::optional<boost::recursive_wrapper<IdentifierNode>>,
        boost::optional<boost::recursive_wrapper<ExprNode>>
>;

//// TODO
//using ParamlistVariantType = boost::optional<
//        boost::tuple<
////                            boost::recursive_wrapper<TypeNode>,
////                            boost::recursive_wrapper<TypemodNode>,
////                            boost::optional<boost::recursive_wrapper<IdentifierNode>>,
////                            boost::optional<boost::recursive_wrapper<ExprNode>>,
//                TypeTypeModIdentifierExprType,
//                std::vector<
//                        TypeTypeModIdentifierExprType
//                >
//        >
//>;
// TODO
using ParamlistVariantType = boost::tuple<
        TypeTypeModIdentifierExprType,
        std::vector<
                TypeTypeModIdentifierExprType
        >
>;

struct ParamlistNode : LocationInfo
{
//    boost::optional<ParamlistVariantType> value;
    std::vector<TypeTypeModIdentifierExprType> value;
//    boost::optional<
//            boost::variant<
//                    std::string,
//                    boost::tuple<
////                            boost::recursive_wrapper<TypeNode>,
////                            boost::recursive_wrapper<TypemodNode>,
////                            boost::optional<boost::recursive_wrapper<IdentifierNode>>,
////                            boost::optional<boost::recursive_wrapper<ExprNode>>,
//                            TypeTypeModIdentifierExprType,
//                            std::vector<
//                                    TypeTypeModIdentifierExprType
//                            >
//                    >
//            >
//    > value;
//    std::string value;
};

}}

#include "ast/TypeNode.hpp"
#include "ast/TypemodNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/ExprNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ParamlistNode,
        value
)

#endif //ICE_SCRIPT_PARAMLISTNODE_HPP
