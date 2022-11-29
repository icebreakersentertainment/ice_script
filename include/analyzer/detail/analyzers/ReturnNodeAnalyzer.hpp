#ifndef ICE_SCRIPT_ANALYZER_RETURNNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_RETURNNODEANALYZER_HPP

#include "ast/ReturnNode.hpp"

#include "asg/Return.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Return process(Context& context, const ast::ReturnNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_RETURNNODEANALYZER_HPP
