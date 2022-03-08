#ifndef ICE_SCRIPT_ANALYZER_SCRIPTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_SCRIPTNODEANALYZER_HPP

#include "ast/ScriptNode.hpp"

#include "asg/Script.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Script process(logger::ILogger& logger, Context& context, const ast::ScriptNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_SCRIPTNODEANALYZER_HPP
