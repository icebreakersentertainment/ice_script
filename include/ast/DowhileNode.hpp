#ifndef ICE_SCRIPT_DOWHILENODE_HPP
#define ICE_SCRIPT_DOWHILENODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct StatementNode;
struct AssignNode;

struct DowhileNode : LocationInfo
{
    boost::recursive_wrapper<StatementNode> statementNode;
    boost::recursive_wrapper<AssignNode> assignNode;
//    std::string value;
};

}}

#include "ast/StatementNode.hpp"
#include "ast/AssignNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::DowhileNode,
        statementNode,
        assignNode
//        value
)

#endif //ICE_SCRIPT_DOWHILENODE_HPP
