#ifndef ICE_SCRIPT_ANALYZER_FUNCATTRNODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_FUNCATTRNODEANALYZER_HPP

#include "ast/FuncattrNode.hpp"

#include "asg/Functionattribute.hpp"

#include "analyzer/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Functionattribute process(logger::ILogger& logger, Context& context, const ast::FuncattrNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_FUNCATTRNODEANALYZER_HPP
