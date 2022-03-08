#ifndef ICE_SCRIPT_ASG_LITERAL_HPP
#define ICE_SCRIPT_ASG_LITERAL_HPP

#include <string>

#include "asg/Number.hpp"
#include "asg/String.hpp"
#include "asg/Bits.hpp"
#include "ast/Boolean.hpp"
#include "ast/Null.hpp"

namespace ice_script { namespace asg {

// LITERAL       ::= NUMBER | STRING | BITS | 'true' | 'false' | 'null'
struct Literal
{
    std::shared_ptr<Type> type;
    boost::variant<Number, String, Bits, ast::Boolean, ast::Null> value;
};

}}

#endif //ICE_SCRIPT_ASG_LITERAL_HPP