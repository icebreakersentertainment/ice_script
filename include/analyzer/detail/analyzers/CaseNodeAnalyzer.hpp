#ifndef ICE_SCRIPT_ANALYZER_CASENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CASENODEANALYZER_HPP

#include "ast/CaseNode.hpp"

#include "asg/Case.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Case process(Context& context, const ast::CaseNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CASENODEANALYZER_HPP
