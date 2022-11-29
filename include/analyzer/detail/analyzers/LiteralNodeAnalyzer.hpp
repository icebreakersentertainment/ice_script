#ifndef ICE_SCRIPT_ANALYZER_LITERALNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_LITERALNODEANALYZER_HPP

#include "ast/LiteralNode.hpp"

#include "asg/Literal.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Literal process(Context& context, const ast::LiteralNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_LITERALNODEANALYZER_HPP
