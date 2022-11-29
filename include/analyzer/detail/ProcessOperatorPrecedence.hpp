#ifndef ICE_SCRIPT_PROCESSOPERATORPRECEDENCE_HPP
#define ICE_SCRIPT_PROCESSOPERATORPRECEDENCE_HPP

#include "ast/ExprNode.hpp"

#include "analyzer/detail/Context.hpp"

#include "logger/ILogger.hpp"

namespace ice_script { namespace analyzer { namespace detail {

ast::ExprNode transformBasedOnOperatorPrecedence(Context& context, const ast::ExprNode& node);

}}}

#endif //ICE_SCRIPT_PROCESSOPERATORPRECEDENCE_HPP
