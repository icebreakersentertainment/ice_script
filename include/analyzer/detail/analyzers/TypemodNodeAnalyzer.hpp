#ifndef ICE_SCRIPT_ANALYZER_TYPEMODNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_TYPEMODNODEANALYZER_HPP

#include "ast/TypemodNode.hpp"

#include "asg/Typemodifier.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Typemodifier process(Context& context, const ast::TypemodNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_TYPEMODNODEANALYZER_HPP
