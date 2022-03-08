#ifndef ICE_SCRIPT_ANALYZER_ENUMNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_ENUMNODEANALYZER_HPP

#include "ast/EnumNode.hpp"

#include "asg/Enumeration.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Enumeration process(logger::ILogger& logger, Context& context, const ast::EnumNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_ENUMNODEANALYZER_HPP
