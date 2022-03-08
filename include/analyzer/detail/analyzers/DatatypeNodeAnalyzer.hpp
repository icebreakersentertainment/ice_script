#ifndef ICE_SCRIPT_ANALYZER_DATATYPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_DATATYPENODEANALYZER_HPP

#include "ast/DatatypeNode.hpp"

#include "asg/Datatype.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Datatype process(logger::ILogger& logger, Context& context, const ast::DatatypeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_DATATYPENODEANALYZER_HPP
