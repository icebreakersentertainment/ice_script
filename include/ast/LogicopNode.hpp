#ifndef ICE_SCRIPT_LOGICOPNODE_HPP
#define ICE_SCRIPT_LOGICOPNODE_HPP

#include <string>

#include "ast/LocationInfo.hpp"
#include "ast/LogicOperator.hpp"

namespace ice_script { namespace ast {

struct LogicopNode : LocationInfo
{
    LogicOperator logicOperator;
};

}}

BOOST_FUSION_ADAPT_STRUCT(
        ice_script::ast::LogicopNode,
        logicOperator
)

#endif //ICE_SCRIPT_LOGICOPNODE_HPP
