#ifndef ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEANALYZER_HPP

#include "ast/ConstructcallNode.hpp"

#include "asg/Constructcall.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Constructcall process(logger::ILogger& logger, Context& context, const ast::ConstructcallNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_CONSTRUCTCALLNODEANALYZER_HPP
