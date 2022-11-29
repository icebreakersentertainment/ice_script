#ifndef ICE_SCRIPT_ANALYZER_IFNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_IFNODEANALYZER_HPP

#include "ast/IfNode.hpp"

#include "asg/If.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::If process(Context& context, const ast::IfNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_IFNODEANALYZER_HPP
