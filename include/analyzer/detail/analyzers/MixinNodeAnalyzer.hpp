#ifndef ICE_SCRIPT_ANALYZER_MIXINNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_MIXINNODEANALYZER_HPP

#include "ast/MixinNode.hpp"

#include "asg/Mixin.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Mixin process(Context& context, const ast::MixinNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_MIXINNODEANALYZER_HPP
