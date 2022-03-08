#ifndef ICE_SCRIPT_ANALYZER_LOGICOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_LOGICOPNODEANALYZER_HPP

#include "ast/LogicopNode.hpp"

#include "asg/Logicoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Logicoperator process(logger::ILogger& logger, Context& context, const ast::LogicopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_LOGICOPNODEANALYZER_HPP
