#ifndef ICE_SCRIPT_TYPENODE_HPP
#define ICE_SCRIPT_TYPENODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/fusion/include/boost_tuple.hpp>
#include <boost/variant/variant.hpp>
#include <boost/optional/optional.hpp>

#include "ast/LocationInfo.hpp"
#include "ast/ScopeNode.hpp"
#include "ast/DatatypeNode.hpp"

namespace ice_script { namespace ast {

struct TypeNode;

typedef boost::optional<std::vector<boost::recursive_wrapper<TypeNode>>> TypeNodeTemplates;

struct TypeNode : LocationInfo
{
    // TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
    boost::optional<std::string> isConst;
    ScopeNode scopeNode;
    DatatypeNode datatypeNode;
    TypeNodeTemplates templates;
    std::vector<
            boost::variant<std::string, boost::tuple<std::string, boost::optional<std::string>>>
    > bracketsOrAtOptionalConst;
//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::TypeNode,
        isConst,
        scopeNode,
        datatypeNode,
        templates,
        bracketsOrAtOptionalConst
//        value
)

#endif //ICE_SCRIPT_TYPENODE_HPP
