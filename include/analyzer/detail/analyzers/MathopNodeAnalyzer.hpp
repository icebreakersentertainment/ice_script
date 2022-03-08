#ifndef ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP

#include "ast/MathopNode.hpp"

#include "asg/Mathoperator.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Mathoperator process(logger::ILogger& logger, Context& context, const ast::MathopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_MATHOPNODEANALYZER_HPP
