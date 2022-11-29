#ifndef ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP

#include "ast/VaraccessNode.hpp"

#include "asg/Variableaccess.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Variableaccess process(Context& context, const ast::VaraccessNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_VARACCESSNODEANALYZER_HPP
