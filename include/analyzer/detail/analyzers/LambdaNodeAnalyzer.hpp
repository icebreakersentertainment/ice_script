#ifndef ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP

#include "ast/LambdaNode.hpp"

#include "asg/Lambda.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Lambda process(Context& context, const ast::LambdaNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_LAMBDANODEANALYZER_HPP
