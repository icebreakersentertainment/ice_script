#ifndef ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP

#include "ast/ExprpostopNode.hpp"

#include "asg/Expressionpostoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionpostoperator process(logger::ILogger& logger, Context& context, const ast::ExprpostopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRPOSTOPNODEANALYZER_HPP
