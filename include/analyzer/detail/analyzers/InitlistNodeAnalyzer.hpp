#ifndef ICE_SCRIPT_ANALYZER_INITLISTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_INITLISTNODEANALYZER_HPP

#include "ast/InitlistNode.hpp"

#include "asg/Initlist.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Initlist process(logger::ILogger& logger, Context& context, const ast::InitlistNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_INITLISTNODEANALYZER_HPP
