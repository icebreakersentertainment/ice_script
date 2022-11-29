#ifndef ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP

#include "ast/PrimtypeNode.hpp"

#include "asg/Primativetype.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Primativetype process(Context& context, const ast::PrimtypeNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_PRIMTYPENODEANALYZER_HPP
