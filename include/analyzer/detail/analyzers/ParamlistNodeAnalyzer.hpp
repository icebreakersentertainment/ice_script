#ifndef ICE_SCRIPT_ANALYZER_PARAMLISTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_PARAMLISTNODEANALYZER_HPP

#include "ast/ParamlistNode.hpp"

#include "asg/Parameterlist.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Parameterlist process(Context& context, const ast::ParamlistNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_PARAMLISTNODEANALYZER_HPP
