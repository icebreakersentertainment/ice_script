#ifndef ICE_SCRIPT_ANALYZER_STATEMENTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_STATEMENTNODEANALYZER_HPP

#include "ast/StatementNode.hpp"

#include "asg/Statement.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Statement process(Context& context, const ast::StatementNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_STATEMENTNODEANALYZER_HPP
