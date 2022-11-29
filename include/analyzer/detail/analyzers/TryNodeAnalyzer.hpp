#ifndef ICE_SCRIPT_ANALYZER_TRYNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_TRYNODEANALYZER_HPP

#include "ast/TryNode.hpp"

#include "asg/Try.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Try process(Context& context, const ast::TryNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_TRYNODEANALYZER_HPP
