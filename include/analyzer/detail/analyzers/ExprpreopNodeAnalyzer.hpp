#ifndef ICE_SCRIPT_ANALYZER_EXPRPREOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRPREOPNODEANALYZER_HPP

#include "ast/ExprpreopNode.hpp"

#include "asg/Expressionpreoperator.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionpreoperator process(Context& context, const ast::ExprpreopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRPREOPNODEANALYZER_HPP
