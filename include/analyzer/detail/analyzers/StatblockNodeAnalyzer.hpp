#ifndef ICE_SCRIPT_ANALYZER_STATBLOCKNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_STATBLOCKNODEANALYZER_HPP

#include "ast/StatblockNode.hpp"

#include "asg/Statblock.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Statblock process(Context& context, const ast::StatblockNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_STATBLOCKNODEANALYZER_HPP
