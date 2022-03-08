#ifndef ICE_SCRIPT_SWITCHNODE_HPP
#define ICE_SCRIPT_SWITCHNODE_HPP

#include <string>
#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct AssignNode;
struct CaseNode;

struct SwitchNode : LocationInfo
{
    boost::recursive_wrapper<AssignNode> assignNode;
    std::vector<boost::recursive_wrapper<CaseNode>> caseNodes;
//    std::string value;
};

}}

#include "ast/AssignNode.hpp"
#include "ast/CaseNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::SwitchNode,
        assignNode,
        caseNodes
//        value
)

#endif //ICE_SCRIPT_SWITCHNODE_HPP
