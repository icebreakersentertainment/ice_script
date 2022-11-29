#ifndef ICE_SCRIPT_ANALYZER_FUNCNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_FUNCNODEANALYZER_HPP

#include "ast/FuncNode.hpp"

#include "asg/Function.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Function process(Context& context, const ast::FuncNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCNODEANALYZER_HPP
