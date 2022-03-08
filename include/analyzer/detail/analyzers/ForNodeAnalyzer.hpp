#ifndef ICE_SCRIPT_ANALYZER_FORNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_FORNODEANALYZER_HPP

#include "ast/ForNode.hpp"

#include "asg/For.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::For process(logger::ILogger& logger, Context& context, const ast::ForNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_FORNODEANALYZER_HPP
