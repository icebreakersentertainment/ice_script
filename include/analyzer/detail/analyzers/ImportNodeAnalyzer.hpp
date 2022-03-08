#ifndef ICE_SCRIPT_ANALYZER_IMPORTNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_IMPORTNODEANALYZER_HPP

#include "ast/ImportNode.hpp"

#include "asg/Import.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Import process(logger::ILogger& logger, Context& context, const ast::ImportNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_IMPORTNODEANALYZER_HPP
