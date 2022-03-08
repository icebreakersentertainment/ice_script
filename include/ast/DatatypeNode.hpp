#ifndef ICE_SCRIPT_DATATYPENODE_HPP
#define ICE_SCRIPT_DATATYPENODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/PrimtypeNode.hpp"

namespace ice_script { namespace ast {

struct DatatypeNode : LocationInfo
{
    // DATATYPE      ::= (IDENTIFIER | PRIMTYPE | '?' | 'auto')
    boost::variant<
            IdentifierNode,
            PrimtypeNode,
            std::string
    > value;
//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::DatatypeNode,
        value
)

#endif //ICE_SCRIPT_DATATYPENODE_HPP
