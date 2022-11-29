#ifndef ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP
#define ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP

#include <string>

#include "symbol/FunctionSymbol.hpp"

#include "asg/Arglist.hpp"
#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

// CONSTRUCTCALL ::= TYPE ARGLIST

struct Constructcall : LocationInfo
{
    std::shared_ptr<FunctionSymbol> symbol;
    boost::recursive_wrapper<Arglist> arglist;
//    std::vector<Argument> arguments;
};

}}

#endif //ICE_SCRIPT_ASG_CONSTRUCTCALL_HPP