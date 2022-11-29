#ifndef ICE_SCRIPT_ANALYZER_EXPRNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_EXPRNODEANALYZER_HPP

#include "ast/ExprNode.hpp"

#include "asg/Expression.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Expression process(Context& context, const ast::ExprNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_EXPRNODEANALYZER_HPP
