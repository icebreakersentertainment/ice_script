#ifndef ICE_SCRIPT_EXPRVALUENODE_HPP
#define ICE_SCRIPT_EXPRVALUENODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

#include "ast/VoidNode.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace ast {

struct ConstructcallNode;
struct FunccallNode;
struct VaraccessNode;
struct CastNode;
struct LiteralNode;
struct AssignNode;
struct LambdaNode;

using ExprvalueNodeValueType = boost::variant<
        monostate,
        VoidNode,
        boost::recursive_wrapper<ConstructcallNode>,
        boost::recursive_wrapper<FunccallNode>,
        boost::recursive_wrapper<VaraccessNode>,
        boost::recursive_wrapper<CastNode>,
        boost::recursive_wrapper<LiteralNode>,
        boost::recursive_wrapper<AssignNode>,
        boost::recursive_wrapper<LambdaNode>
>;

struct ExprvalueNode : LocationInfo
{
    // (string("void") | constructcallRule | funccallRule | varaccessRule | castRule | literalRule | (lit("(") >> assignRule >> lit(")")) | lambdaRule);
    ExprvalueNodeValueType value;
//    std::string value;
};

}}

#include "ast/ConstructcallNode.hpp"
#include "ast/FunccallNode.hpp"
#include "ast/VaraccessNode.hpp"
#include "ast/CastNode.hpp"
#include "ast/LiteralNode.hpp"
#include "ast/AssignNode.hpp"
#include "ast/LambdaNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ExprvalueNode,
        value
)

#endif //ICE_SCRIPT_EXPRVALUENODE_HPP
