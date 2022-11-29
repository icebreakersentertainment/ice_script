#ifndef ICE_SCRIPT_ANALYZER_SWITCHNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_SWITCHNODEANALYZER_HPP

#include "ast/SwitchNode.hpp"

#include "asg/Switch.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Switch process(Context& context, const ast::SwitchNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_SWITCHNODEANALYZER_HPP
