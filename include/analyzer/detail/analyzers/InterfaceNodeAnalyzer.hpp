#ifndef ICE_SCRIPT_ANALYZER_INTERFACENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_INTERFACENODEANALYZER_HPP

#include "ast/InterfaceNode.hpp"

#include "asg/Interface.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Interface process(Context& context, const ast::InterfaceNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_INTERFACENODEANALYZER_HPP
