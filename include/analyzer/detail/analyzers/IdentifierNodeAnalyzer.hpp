#ifndef ICE_SCRIPT_ANALYZER_IDENTIFIERNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_IDENTIFIERNODEANALYZER_HPP

#include "ast/IdentifierNode.hpp"

#include "asg/Identifier.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Identifier process(logger::ILogger& logger, Context& context, const ast::IdentifierNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_IDENTIFIERNODEANALYZER_HPP
