#ifndef ICE_SCRIPT_ANALYZER_DOWHILENODEANALYZER_HPP
#define ICE_SCRIPT_ANALYZER_DOWHILENODEANALYZER_HPP

#include "ast/DowhileNode.hpp"

#include "asg/Dowhile.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

asg::Dowhile process(Context& context, const ast::DowhileNode& node);

}}}

#endif //ICE_SCRIPT_ANALYZER_DOWHILENODEANALYZER_HPP
