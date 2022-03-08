#ifndef ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP

#include "ast/PrimtypeNode.hpp"

#include "asg/Primativetype.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Primativetype process(logger::ILogger& logger, Context& context, const ast::PrimtypeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP
