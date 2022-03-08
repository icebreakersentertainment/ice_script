#ifndef ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP

#include "ast/LambdaNode.hpp"

#include "asg/Lambda.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Lambda process(logger::ILogger& logger, Context& context, const ast::LambdaNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP
