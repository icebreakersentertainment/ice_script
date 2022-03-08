#ifndef ICE_SCRIPT_SCRIPTNODE_HPP
#define ICE_SCRIPT_SCRIPTNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"

namespace ice_script { namespace ast {

struct ImportNode;
struct EnumNode;
struct TypedefNode;
struct ClassNode;
struct MixinNode;
struct InterfaceNode;
struct FuncdefNode;
struct VirtpropNode;
struct VarNode;
struct FuncNode;
struct NamespaceNode;

using Node = boost::variant<
        boost::recursive_wrapper<ImportNode>,
        boost::recursive_wrapper<EnumNode>,
        boost::recursive_wrapper<TypedefNode>,
        boost::recursive_wrapper<ClassNode>,
        boost::recursive_wrapper<MixinNode>,
        boost::recursive_wrapper<InterfaceNode>,
        boost::recursive_wrapper<FuncdefNode>,
        boost::recursive_wrapper<VirtpropNode>,
        boost::recursive_wrapper<VarNode>,
        boost::recursive_wrapper<FuncNode>,
        boost::recursive_wrapper<NamespaceNode>,
        std::string
>;

struct ScriptNode : LocationInfo
{
    std::vector<Node> value;
//    std::string value;
};

}}

#include "ast/ImportNode.hpp"
#include "ast/EnumNode.hpp"
#include "ast/TypedefNode.hpp"
#include "ast/ClassNode.hpp"
#include "ast/MixinNode.hpp"
#include "ast/InterfaceNode.hpp"
#include "ast/FuncdefNode.hpp"
#include "ast/VirtpropNode.hpp"
#include "ast/VarNode.hpp"
#include "ast/FuncNode.hpp"
#include "ast/NamespaceNode.hpp"

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::ScriptNode,
        value
)

#endif //ICE_SCRIPT_SCRIPTNODE_HPP
