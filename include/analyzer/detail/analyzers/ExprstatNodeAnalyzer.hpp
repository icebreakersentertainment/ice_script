#ifndef ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP

#include "ast/ExprstatNode.hpp"

#include "asg/Expressionstat.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expressionstat process(logger::ILogger& logger, Context& context, const ast::ExprstatNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRSTATNODEANALYZER_HPP
