#ifndef ICE_SCRIPT_ANALYZER_INTFMTHDNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_INTFMTHDNODEANALYZER_HPP

#include "ast/IntfmthdNode.hpp"

#include "asg/Interfacemethod.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Interfacemethod process(Context& context, const ast::IntfmthdNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_INTFMTHDNODEANALYZER_HPP
