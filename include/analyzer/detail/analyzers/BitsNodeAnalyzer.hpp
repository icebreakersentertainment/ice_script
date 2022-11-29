#ifndef ICE_SCRIPT_ANALYZER_BITSNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_BITSNODEANALYZER_HPP

#include "ast/BitsNode.hpp"

#include "asg/Bits.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Bits process(Context& context, const ast::BitsNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_BITSNODEANALYZER_HPP
