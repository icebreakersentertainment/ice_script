#ifndef ICE_SCRIPT_ANALYZER_ASSIGNNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_ASSIGNNODEANALYZER_HPP

#include "ast/AssignNode.hpp"

#include "asg/Assign.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Assign process(Context& context, const ast::AssignNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_ASSIGNNODEANALYZER_HPP
