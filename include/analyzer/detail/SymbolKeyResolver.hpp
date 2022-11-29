#ifndef ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLKEYRESOLVER_HPP
#define ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLKEYRESOLVER_HPP

#include <string>

#include "ast/ClassNode.hpp"
#include "ast/FuncNode.hpp"

#include "analyzer/detail/Context.hpp"

namespace ice_script { namespace analyzer { namespace detail {

// std::string resolveSymbolKey(const Context& context, const std::shared_ptr<ClassType>& type);

std::string resolveSymbolKey(const Context& context, const ast::TypeNode& node);
std::string resolveSymbolKey(const Context& context, const ast::ClassNode& node);
std::string resolveSymbolKey(const Context& context, const ast::FuncNode& node);
std::string resolveSymbolKey(const Context& context, const ast::VarNode& node);
std::string resolveSymbolKey(const Context& context, const ast::ConstructcallNode& node);

}}}

#endif /* ICE_SCRIPT_ANALYZER_DETAIL_SYMBOLKEYRESOLVER_HPP */
