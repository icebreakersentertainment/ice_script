#ifndef ICE_SCRIPT_ANALYZER_COMPOPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_COMPOPNODEANALYZER_HPP

#include "ast/CompopNode.hpp"

#include "asg/Comparisonoperator.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Comparisonoperator process(Context& context, const ast::CompopNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_COMPOPNODEANALYZER_HPP
