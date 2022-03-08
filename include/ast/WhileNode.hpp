#ifndef ICE_SCRIPT_WHILENODE_HPP
#define ICE_SCRIPT_WHILENODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct AssignNode;
struct StatementNode;

struct WhileNode : LocationInfo
{
    boost::recursive_wrapper<AssignNode> assignNode;
    boost::recursive_wrapper<StatementNode> statementNode;
//    std::string value;
};

}}

#include "ast/AssignNode.hpp"
#include "ast/StatementNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::WhileNode,
        assignNode,
        statementNode
//        value
)

#endif //ICE_SCRIPT_WHILENODE_HPP
