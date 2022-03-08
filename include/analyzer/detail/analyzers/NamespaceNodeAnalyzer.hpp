#ifndef ICE_SCRIPT_ANALYZER_NAMESPACENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_NAMESPACENODEANALYZER_HPP

#include "ast/NamespaceNode.hpp"

#include "asg/Namespace.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Namespace process(logger::ILogger& logger, Context& context, const ast::NamespaceNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_NAMESPACENODEANALYZER_HPP
