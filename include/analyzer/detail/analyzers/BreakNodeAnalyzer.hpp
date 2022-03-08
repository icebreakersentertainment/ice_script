#ifndef ICE_SCRIPT_ANALYZER_BREAKNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_BREAKNODEANALYZER_HPP

#include "ast/BreakNode.hpp"

#include "asg/Break.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Break process(logger::ILogger& logger, Context& context, const ast::BreakNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_BREAKNODEANALYZER_HPP
