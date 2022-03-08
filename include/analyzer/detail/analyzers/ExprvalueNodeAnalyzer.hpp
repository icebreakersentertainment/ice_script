#ifndef ICE_SCRIPT_ANALYZER_EXPRVALUENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRVALUENODEANALYZER_HPP

#include "ast/ExprvalueNode.hpp"

#include "asg/Expressionvalue.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionvalue process(logger::ILogger& logger, Context& context, const ast::ExprvalueNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRVALUENODEANALYZER_HPP
