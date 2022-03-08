#ifndef ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP

#include "ast/VaraccessNode.hpp"

#include "asg/Variableaccess.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Variableaccess process(logger::ILogger& logger, Context& context, const ast::VaraccessNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP
