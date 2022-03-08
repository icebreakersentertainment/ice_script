#ifndef ICE_SCRIPT_ANALYZER_CONDITIONNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CONDITIONNODEANALYZER_HPP

#include "ast/ConditionNode.hpp"

#include "asg/Condition.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Condition process(logger::ILogger& logger, Context& context, const ast::ConditionNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CONDITIONNODEANALYZER_HPP
