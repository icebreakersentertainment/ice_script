#ifndef ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP

#include "ast/TypeNode.hpp"

#include "asg/Type.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Type process(logger::ILogger& logger, Context& context, const ast::TypeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPENODEANALYZER_HPP
