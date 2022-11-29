#ifndef ICE_SCRIPT_ANALYZER_STRINGNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_STRINGNODEANALYZER_HPP

#include "ast/StringNode.hpp"

#include "asg/String.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::String process(Context& context, const ast::StringNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_STRINGNODEANALYZER_HPP
