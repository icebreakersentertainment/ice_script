#ifndef ICE_SCRIPT_ANALYZER_CLASSNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CLASSNODEANALYZER_HPP

#include "ast/ClassNode.hpp"

#include "asg/Class.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Class process(Context& context, const ast::ClassNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CLASSNODEANALYZER_HPP
