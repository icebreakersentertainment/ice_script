#ifndef ICE_SCRIPT_ANALYZER_VARNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_VARNODEANALYZER_HPP

#include "ast/VarNode.hpp"

#include "asg/Variable.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Variable process(Context& context, const ast::VarNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_VARNODEANALYZER_HPP
