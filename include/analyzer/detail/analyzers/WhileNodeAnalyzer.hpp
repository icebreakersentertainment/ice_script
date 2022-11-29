#ifndef ICE_SCRIPT_ANALYZER_WHILENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_WHILENODEANALYZER_HPP

#include "ast/WhileNode.hpp"

#include "asg/While.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::While process(Context& context, const ast::WhileNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_WHILENODEANALYZER_HPP
