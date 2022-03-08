#ifndef ICE_SCRIPT_ANALYZER_BITOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_BITOPNODEANALYZER_HPP

#include "ast/BitopNode.hpp"

#include "asg/Bitoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Bitoperator process(logger::ILogger& logger, Context& context, const ast::BitopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_BITOPNODEANALYZER_HPP
