#ifndef ICE_SCRIPT_ANALYZER_SCOPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_SCOPENODEANALYZER_HPP

#include "ast/ScopeNode.hpp"

#include "asg/Scoperatore.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Scoperatore process(Context& context, const ast::ScopeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_SCOPENODEANALYZER_HPP
