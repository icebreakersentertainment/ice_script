#ifndef ICE_SCRIPT_ROOT_HPP
#define ICE_SCRIPT_ROOT_HPP

#include <vector>

#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_LIST_SIZE 50

#include <boost/variant/variant.hpp>
#include <boost/fusion/include/adapt_struct.hpp>

#include "ast/LocationInfo.hpp"
#include "ast/ScriptNode.hpp"
#include "ast/ClassNode.hpp"
#include "ast/TypedefNode.hpp"
#include "ast/NamespaceNode.hpp"
#include "ast/FuncNode.hpp"
#include "ast/InterfaceNode.hpp"
#include "ast/VarNode.hpp"
#include "ast/ImportNode.hpp"
#include "ast/EnumNode.hpp"
#include "ast/FuncdefNode.hpp"
#include "ast/VirtpropNode.hpp"
#include "ast/MixinNode.hpp"
#include "ast/IntfmthdNode.hpp"
#include "ast/StatblockNode.hpp"
#include "ast/ParamlistNode.hpp"
#include "ast/TypemodNode.hpp"
#include "ast/TypeNode.hpp"
#include "ast/InitlistNode.hpp"
#include "ast/ScopeNode.hpp"
#include "ast/DatatypeNode.hpp"
#include "ast/PrimtypeNode.hpp"
#include "ast/FuncattrNode.hpp"
#include "ast/StatementNode.hpp"
#include "ast/SwitchNode.hpp"
#include "ast/BreakNode.hpp"
#include "ast/ForNode.hpp"
#include "ast/WhileNode.hpp"
#include "ast/DowhileNode.hpp"
#include "ast/IfNode.hpp"
#include "ast/ContinueNode.hpp"
#include "ast/ExprstatNode.hpp"
#include "ast/TryNode.hpp"
#include "ast/ReturnNode.hpp"
#include "ast/CaseNode.hpp"
#include "ast/ExprNode.hpp"
#include "ast/ExprtermNode.hpp"
#include "ast/ExprvalueNode.hpp"
#include "ast/ConstructcallNode.hpp"
#include "ast/ExprpreopNode.hpp"
#include "ast/ExprpostopNode.hpp"
#include "ast/CastNode.hpp"
#include "ast/LambdaNode.hpp"
#include "ast/LiteralNode.hpp"
#include "ast/FunccallNode.hpp"
#include "ast/VaraccessNode.hpp"
#include "ast/ArglistNode.hpp"
#include "ast/AssignNode.hpp"
#include "ast/ConditionNode.hpp"
#include "ast/ExpropNode.hpp"
#include "ast/BitopNode.hpp"
#include "ast/MathopNode.hpp"
#include "ast/CompopNode.hpp"
#include "ast/LogicopNode.hpp"
#include "ast/AssignopNode.hpp"
#include "ast/IdentifierNode.hpp"
#include "ast/NumberNode.hpp"
#include "ast/StringNode.hpp"
#include "ast/BitsNode.hpp"

namespace ice_script { namespace ast {

struct Root : LocationInfo
{
    ScriptNode scriptNode;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::Root,
        scriptNode
//        values
)

#endif //ICE_SCRIPT_ROOT_HPP
