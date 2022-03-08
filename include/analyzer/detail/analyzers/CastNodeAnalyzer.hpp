#ifndef ICE_SCRIPT_ANALYZER_CASTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CASTNODEANALYZER_HPP

#include "ast/CastNode.hpp"

#include "asg/Cast.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Cast process(logger::ILogger& logger, Context& context, const ast::CastNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CASTNODEANALYZER_HPP
