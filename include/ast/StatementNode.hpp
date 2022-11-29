#ifndef ICE_SCRIPT_STATEMENTNODE_HPP
#define ICE_SCRIPT_STATEMENTNODE_HPP

#include <string>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/spirit/include/qi.hpp>
#include <boost/variant/variant.hpp>
#include <boost/variant/recursive_wrapper.hpp>

#include "ast/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct IfNode;
struct ForNode;
struct WhileNode;
struct ReturnNode;
struct StatblockNode;
struct BreakNode;
struct ContinueNode;
struct DowhileNode;
struct SwitchNode;
struct ExprstatNode;
struct TryNode;

struct StatementNode : LocationInfo
{
    boost::variant<
            // This is here to allow the variant to be default constructed without running into recursion issues
            monostate,
            boost::recursive_wrapper<IfNode>,
            boost::recursive_wrapper<ForNode>,
            boost::recursive_wrapper<WhileNode>,
            boost::recursive_wrapper<ReturnNode>,
            boost::recursive_wrapper<StatblockNode>,
            boost::recursive_wrapper<BreakNode>,
            boost::recursive_wrapper<ContinueNode>,
            boost::recursive_wrapper<DowhileNode>,
            boost::recursive_wrapper<SwitchNode>,
            boost::recursive_wrapper<ExprstatNode>,
            boost::recursive_wrapper<TryNode>
    > value;
//    std::string value;
};

}}

#include "ast/IfNode.hpp"
#include "ast/ForNode.hpp"
#include "ast/WhileNode.hpp"
#include "ast/ReturnNode.hpp"
#include "ast/StatblockNode.hpp"
#include "ast/BreakNode.hpp"
#include "ast/ContinueNode.hpp"
#include "ast/DowhileNode.hpp"
#include "ast/SwitchNode.hpp"
#include "ast/ExprstatNode.hpp"
#include "ast/TryNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::StatementNode,
        value
)

#endif //ICE_SCRIPT_STATEMENTNODE_HPP
