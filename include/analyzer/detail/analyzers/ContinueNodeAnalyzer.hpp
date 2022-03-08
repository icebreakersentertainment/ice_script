#ifndef ICE_SCRIPT_ANALYZER_CONTINUENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CONTINUENODEANALYZER_HPP

#include "ast/ContinueNode.hpp"

#include "asg/Continue.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Continue process(logger::ILogger& logger, Context& context, const ast::ContinueNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CONTINUENODEANALYZER_HPP
