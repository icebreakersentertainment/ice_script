#ifndef ICE_SCRIPT_TYPENODE_HPP
#define ICE_SCRIPT_TYPENODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/optional/optional.hpp>

#include "type/TypeQualifier.hpp"
#include "type/TypeModifier.hpp"

#include "ast/LocationInfo.hpp"
#include "ast/ScopeNode.hpp"
#include "ast/DatatypeNode.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct TypeNode;

using TypeNodeTemplates = boost::optional<std::vector<boost::recursive_wrapper<TypeNode>>>;

struct TypeNode : LocationInfo
{
    // TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
    std::vector<TypeQualifier::TypeQualifierFlags> typeQualifiers;
    // boost::optional<TypeQualifier::TypeQualifierFlags> typeQualifiers;
    ScopeNode scopeNode;
    DatatypeNode datatypeNode;
    TypeNodeTemplates templates;
//     std::vector<
//             boost::variant<monostate, std::string, boost::tuple<std::string, boost::optional<std::string>>>
//     > bracketsOrAtOptionalConst;
    std::vector<boost::optional<uint32_t>> array;
    boost::optional<TypeModifier> typeModifier;
    bool constant;
//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::TypeNode,
        typeQualifiers,
        scopeNode,
        datatypeNode,
        templates,
        // bracketsOrAtOptionalConst,
        array,
        typeModifier,
        constant
//        value
)

#endif //ICE_SCRIPT_TYPENODE_HPP
