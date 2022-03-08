#ifndef ICE_SCRIPT_ASG_FUNCTIONCALL_HPP
#define ICE_SCRIPT_ASG_FUNCTIONCALL_HPP

#include <string>

#include "asg/Scoperatore.hpp"
#include "asg/Identifier.hpp"

#include "asg/FunctionType.hpp"

namespace ice_script { namespace asg {

struct Arglist;

// FUNCCALL      ::= SCOPE IDENTIFIER ARGLIST
struct Functioncall
{
    std::shared_ptr<asg::FunctionType> type;
    std::string name;
    boost::recursive_wrapper<Arglist> arglist;
//    boost::recursive_wrapper<ScopeNode> scopeNode;
//    boost::recursive_wrapper<IdentifierNode> identifierNode;
//    boost::recursive_wrapper<ArglistNode> arglistNode;
    std::string value;
};

}}

#include "asg/Arglist.hpp"

#endif //ICE_SCRIPT_ASG_FUNCTIONCALL_HPP