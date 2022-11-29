#ifndef ICE_SCRIPT_ANALYZER_DETAIL_TYPEKEYRESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_DETAIL_TYPEKEYRESOLVER_HPP

#include "type/Type.hpp"

#include "ast/TypeNode.hpp"
#include "ast/PrimtypeNode.hpp"
#include "ast/ClassNode.hpp"
#include "ast/FuncNode.hpp"
#include "ast/VarNode.hpp"

#include "analyzer/detail/Context.hpp"


namespace ice_script { namespace analyzer { namespace detail {

std::string resolveTypeKey(const Type::TypeId typeId);
std::string resolveTypeKey(const ast::PrimitiveType primitiveType);
std::string resolveTypeKey(const Context& context, const ast::TypeNode& node);
std::string resolveTypeKey(const Context& context, const ast::ClassNode& node);
std::string resolveTypeKey(const Context& context, const ast::FuncNode& node);
std::string resolveTypeKey(const Context& context, const ast::TypeTypeModIdentifierExpr& node);
std::string resolveTypeKey(const Context& context, const ast::VarNode& node);
std::string resolveArrayElementTypeKey(const Context& context, const ast::TypeNode& node);

}}}

#endif /* ICE_SCRIPT_ANALYZER_DETAIL_TYPEKEYRESOLVER_HPP */
