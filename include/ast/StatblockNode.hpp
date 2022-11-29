#ifndef ICE_SCRIPT_STATBLOCKNODE_HPP
#define ICE_SCRIPT_STATBLOCKNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/VarNode.hpp"
#include "ast/StatementNode.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct StatblockNode : LocationInfo
{
    StatblockNode() = default;
    
    StatblockNode(std::vector<boost::variant<monostate, VarNode, StatementNode>> v) : value(std::move(v))
    {
        
    }
    
    std::vector<boost::variant<monostate, VarNode, StatementNode>> value;
//    std::string value;
};

}}

// BOOST_FUSION_ADAPT_STRUCT(
//         ice_script::ast::StatblockNode,
//         value
// )

#endif //ICE_SCRIPT_STATBLOCKNODE_HPP
