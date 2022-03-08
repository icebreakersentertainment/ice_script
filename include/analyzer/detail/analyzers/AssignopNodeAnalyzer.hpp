#ifndef ICE_SCRIPT_ANALYZER_ASSIGNOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_ASSIGNOPNODEANALYZER_HPP

#include "ast/AssignopNode.hpp"

#include "asg/Assignoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Assignoperator process(logger::ILogger& logger, Context& context, const ast::AssignopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_ASSIGNOPNODEANALYZER_HPP
