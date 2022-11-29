#ifndef ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP

#include "ast/ExprpostopNode.hpp"

#include "asg/Expressionpostoperator.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionpostoperator process(Context& context, const ast::ExprpostopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP
