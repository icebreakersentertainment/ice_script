#ifndef ICE_SCRIPT_ANALYZER_EXPROPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPROPNODEANALYZER_HPP

#include "ast/ExpropNode.hpp"

#include "asg/Expressionoperatorerty.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionoperatorerty process(logger::ILogger& logger, Context& context, const ast::ExpropNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPROPNODEANALYZER_HPP
