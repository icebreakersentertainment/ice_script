#ifndef ICE_SCRIPT_CLASSNODE_HPP
#define ICE_SCRIPT_CLASSNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/recursive_wrapper.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct IdentifierNode;
struct VirtpropNode;
struct FuncNode;
struct VarNode;
struct FuncdefNode;

using VariantVirtualPropertyFunctionVariableFunctionDefinitionType = boost::variant<
        monostate,
        boost::recursive_wrapper<VirtpropNode>,
        boost::recursive_wrapper<FuncNode>,
        boost::recursive_wrapper<VarNode>,
        boost::recursive_wrapper<FuncdefNode>
>;

struct ClassData
{
    boost::optional<
//                            boost::tuple<
//                                boost::spirit::qi::unused_type,
//                                boost::recursive_wrapper<IdentifierNode>,
                                std::vector<boost::recursive_wrapper<IdentifierNode>>
//                            >
    > extendsAndImplements;
    std::vector<VariantVirtualPropertyFunctionVariableFunctionDefinitionType> virtualPropertyFunctionVariableFunctionDefinitions;
};

struct ClassNode : LocationInfo
{
    std::vector<std::string> type;
    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    ClassData value;
//    boost::variant<
//            boost::spirit::qi::unused_type,
//            boost::tuple<
//                    boost::optional<
////                            boost::tuple<
////                                boost::spirit::qi::unused_type,
////                                boost::recursive_wrapper<IdentifierNode>,
//                                std::vector<boost::recursive_wrapper<IdentifierNode>>
////                            >
//                    >,
//                    std::vector<
//                            boost::variant<
//                                    boost::recursive_wrapper<VirtpropNode>,
//                                    boost::recursive_wrapper<FuncNode>,
//                                    boost::recursive_wrapper<VarNode>,
//                                    boost::recursive_wrapper<FuncdefNode>
//                            >
//                    >
//            >
//    > value;
    boost::optional<ClassData> value;

//    std::string value;
};

}}

#include "ast/IdentifierNode.hpp"
#include "ast/VirtpropNode.hpp"
#include "ast/FuncNode.hpp"
#include "ast/VarNode.hpp"
#include "ast/FuncdefNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ClassData,
        extendsAndImplements,
        virtualPropertyFunctionVariableFunctionDefinitions
)

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ClassNode,
        type,
        identifierNode,
        value
)

#endif //ICE_SCRIPT_CLASSNODE_HPP
