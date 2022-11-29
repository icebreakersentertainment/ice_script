#ifndef ICE_SCRIPT_ASG_LITERAL_HPP
#define ICE_SCRIPT_ASG_LITERAL_HPP

#include <string>

#include "asg/Number.hpp"
#include "asg/String.hpp"
#include "asg/Bits.hpp"
#include "ast/Boolean.hpp"
#include "ast/Null.hpp"
#include "asg/LocationInfo.hpp"

#include "detail/monostate.hpp"

namespace ice_script { namespace asg {

using LiteralType = boost::variant<monostate, Number, String, Bits, ast::Boolean, ast::Null>;

// LITERAL       ::= NUMBER | STRING | BITS | 'true' | 'false' | 'null'
struct Literal : LocationInfo
{
//    std::shared_ptr<Type> type;
    LiteralType value;
};

}}

#endif //ICE_SCRIPT_ASG_LITERAL_HPP