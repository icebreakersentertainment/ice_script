#ifndef ICE_SCRIPT_ASG_ARGLIST_HPP
#define ICE_SCRIPT_ASG_ARGLIST_HPP

#include "asg/LocationInfo.hpp"

namespace ice_script { namespace asg {

struct Identifier;
struct Assign;

struct Argument
{
    Argument() = default;

    Argument(boost::recursive_wrapper<Assign> assign) : assign(std::move(assign))
    {}
    
    Argument(std::string name, boost::recursive_wrapper<Assign> assign) : name(std::move(name)), assign(std::move(assign))
    {}

    boost::optional<std::string> name;
    boost::recursive_wrapper<Assign> assign;
};

// ARGLIST       ::= '(' [IDENTIFIER ':'] ASSIGN {',' [IDENTIFIER ':'] ASSIGN} ')'
struct Arglist : LocationInfo
{
    Arglist() = default;
    
    Arglist(std::vector<Argument> arguments) : arguments(std::move(arguments))
    {
        
    }
    
    std::vector<Argument> arguments;
//    std::string value;
};

}}

#include "asg/Identifier.hpp"
#include "asg/Assign.hpp"

#endif //ICE_SCRIPT_ASG_ARGLIST_HPP