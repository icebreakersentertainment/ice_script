#ifndef ICE_SCRIPT_EXPROPNODE_HPP
#define ICE_SCRIPT_EXPROPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/BitopNode.hpp"
#include "ast/MathopNode.hpp"
#include "ast/CompopNode.hpp"
#include "ast/LogicopNode.hpp"

namespace ice_script { namespace ast {

struct ExpropNode : LocationInfo
{
    //    EXPROP        ::= MATHOP | COMPOP | LOGICOP | BITOP
    boost::variant<BitopNode, MathopNode, CompopNode, LogicopNode> value;
//    std::string value;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExpropNode,
        value
)

#endif //ICE_SCRIPT_EXPROPNODE_HPP
