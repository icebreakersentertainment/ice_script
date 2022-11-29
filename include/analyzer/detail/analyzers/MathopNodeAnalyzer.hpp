#ifndef ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP

#include "ast/MathopNode.hpp"

#include "asg/Mathoperator.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Mathoperator process(Context& context, const ast::MathopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP
