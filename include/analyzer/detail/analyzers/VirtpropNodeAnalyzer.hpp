#ifndef ICE_SCRIPT_ANALYZER_VIRTPROPNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_VIRTPROPNODEANALYZER_HPP

#include "ast/VirtpropNode.hpp"

#include "asg/Virtualproperatorerty.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Virtualproperatorerty process(logger::ILogger& logger, Context& context, const ast::VirtpropNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_VIRTPROPNODEANALYZER_HPP
