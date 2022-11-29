#ifndef ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP

#include "ast/TypeNode.hpp"

#include "type/Type.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

Type process(Context& context, const ast::TypeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP
