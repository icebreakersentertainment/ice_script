#ifndef ICE_SCRIPT_ANALYZER_FUNCDEFNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_FUNCDEFNODEANALYZER_HPP

#include "ast/FuncdefNode.hpp"

#include "asg/Functiondefinition.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Functiondefinition process(Context& context, const ast::FuncdefNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCDEFNODEANALYZER_HPP
