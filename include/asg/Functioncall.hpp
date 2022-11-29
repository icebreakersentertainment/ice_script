#ifndef ICE_SCRIPT_ASG_FUNCTIONCALL_HPP
#define ICE_SCRIPT_ASG_FUNCTIONCALL_HPP

#include <string>

#include "asg/Scoperatore.hpp"
#include "asg/Identifier.hpp"
#include "asg/LocationInfo.hpp"

#include "symbol/FunctionSymbol.hpp"
#include "type/FunctionType.hpp"

namespace ice_script { namespace asg {

struct Arglist;
struct Assign;

// struct Argument
// {
//     Argument() = default;

//     Argument(boost::recursive_wrapper<Assign> assign) : assign(std::move(assign))
//     {}
    
//     Argument(std::string name, boost::recursive_wrapper<Assign> assign) : name(std::move(name)), assign(std::move(assign))
//     {}

//     std::string name;
//     boost::recursive_wrapper<Assign> assign;
// };

// FUNCCALL      ::= SCOPE IDENTIFIER ARGLIST
struct Functioncall : LocationInfo
{
    Functioncall() = default;
    
    // Functioncall(std::shared_ptr<FunctionSymbol> symbol, std::shared_ptr<FunctionType> type, std::vector<Argument> arguments)
    Functioncall(std::shared_ptr<FunctionSymbol> symbol, std::shared_ptr<FunctionType> type, boost::recursive_wrapper<Arglist> arglist)
        :
        symbol(std::move(symbol)),
        type(std::move(type)),
        // arguments(std::move(arguments))
        arglist(std::move(arglist))
    {}
    
    std::shared_ptr<FunctionSymbol> symbol;
    std::shared_ptr<FunctionType> type;
    std::string name;
    boost::recursive_wrapper<Arglist> arglist;
    // std::vector<Argument> arguments;
//    boost::recursive_wrapper<ScopeNode> scopeNode;
//    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    boost::recursive_wrapper<ArglistNode> arglistNode;
    std::string value;
};

}}

#include "asg/Arglist.hpp"
#include "asg/Assign.hpp"

#endif //ICE_SCRIPT_ASG_FUNCTIONCALL_HPP