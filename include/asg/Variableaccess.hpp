#ifndef ICE_SCRIPT_ASG_VARIABLEACCESS_HPP
#define ICE_SCRIPT_ASG_VARIABLEACCESS_HPP

#include <string>

#include "asg/Scoperatore.hpp"
#include "asg/Identifier.hpp"
#include "asg/LocationInfo.hpp"

#include "symbol/Symbol.hpp"

namespace ice_script { namespace asg {

// VARACCESS     ::= SCOPE IDENTIFIER
struct Variableaccess : LocationInfo
{
    Variableaccess() = default;
    
    Variableaccess(std::shared_ptr<Symbol> symbol, std::shared_ptr<Type> type) : symbol(std::move(symbol)), type(std::move(type))
    {}
    
    std::shared_ptr<Symbol> symbol;
    std::shared_ptr<Type> type;
    Scoperatore scope;
};

}}

#endif //ICE_SCRIPT_ASG_VARIABLEACCESS_HPP