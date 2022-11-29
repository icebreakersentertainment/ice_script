#ifndef ICE_SCRIPT_ANALYZER_TYPEDEFNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_TYPEDEFNODEANALYZER_HPP

#include "ast/TypedefNode.hpp"

#include "asg/Typedefinition.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Typedefinition process(Context& context, const ast::TypedefNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPEDEFNODEANALYZER_HPP
