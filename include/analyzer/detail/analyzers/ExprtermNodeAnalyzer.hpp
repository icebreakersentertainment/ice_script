#ifndef ICE_SCRIPT_ANALYZER_EXPRTERMNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRTERMNODEANALYZER_HPP

#include "ast/ExprtermNode.hpp"

#include "asg/Expressionterm.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionterm process(Context& context, const ast::ExprtermNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRTERMNODEANALYZER_HPP
