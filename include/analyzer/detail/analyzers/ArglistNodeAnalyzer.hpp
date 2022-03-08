#ifndef ICE_SCRIPT_ANALYZER_ARGLISTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_ARGLISTNODEANALYZER_HPP

#include "ast/ArglistNode.hpp"

#include "asg/Arglist.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Arglist process(logger::ILogger& logger, Context& context, const ast::ArglistNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_ARGLISTNODEANALYZER_HPP
