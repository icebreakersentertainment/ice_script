#ifndef ICE_SCRIPT_ANALYZER_NUMBERNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_NUMBERNODEANALYZER_HPP

#include "ast/NumberNode.hpp"

#include "asg/Number.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Number process(logger::ILogger& logger, Context& context, const ast::NumberNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_NUMBERNODEANALYZER_HPP
