#ifndef ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP

#include "ast/ExprstatNode.hpp"

#include "asg/Expressionstat.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionstat process(Context& context, const ast::ExprstatNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP
