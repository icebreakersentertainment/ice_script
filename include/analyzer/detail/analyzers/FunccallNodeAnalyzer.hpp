#ifndef ICE_SCRIPT_ANALYZER_FUNCCALLNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_FUNCCALLNODEANALYZER_HPP

#include "ast/FunccallNode.hpp"

#include "asg/Functioncall.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Functioncall process(Context& context, const ast::FunccallNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCCALLNODEANALYZER_HPP
