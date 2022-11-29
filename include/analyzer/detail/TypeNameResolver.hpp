#ifndef ICE_SCRIPT_ANALYZER_DETAIL_TYPENAMERESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_DETAIL_TYPENAMERESOLVER_HPP

#include <string>

#include "type/Type.hpp"

#include "ast/TypeNode.hpp"
#include "ast/PrimtypeNode.hpp"
#include "ast/DatatypeNode.hpp"

namespace ice_script { namespace analyzer { namespace detail {

std::string resolveTypeName(const Type::TypeId typeId);
std::string resolveTypeName(const ast::PrimitiveType primitiveType);
std::string resolveTypeName(const ast::IdentifierNode& node);
std::string resolveTypeName(const ast::DatatypeNode& node);

}}}

#endif /* ICE_SCRIPT_ANALYZER_DETAIL_TYPENAMERESOLVER_HPP */
