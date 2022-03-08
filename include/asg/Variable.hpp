#ifndef ICE_SCRIPT_ASG_VARIABLE_HPP
#define ICE_SCRIPT_ASG_VARIABLE_HPP

#include <string>

#include "asg/Type.hpp"
//#include "asg/Arglist.hpp"

namespace ice_script { namespace asg {

struct Initlist;
struct Expression;
//struct Constructcall;
struct Arglist;

// VAR           ::= ['private'|'protected'] TYPE IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST] {',' IDENTIFIER [( '=' (INITLIST | EXPR)) | ARGLIST]} ';'
struct Variable
{
    std::shared_ptr<Type> type;
    std::string name;
//    boost::variant<boost::recursive_wrapper<Initlist>, boost::recursive_wrapper<Expression>, boost::recursive_wrapper<Constructcall>> value;
    boost::variant<boost::recursive_wrapper<Initlist>, boost::recursive_wrapper<Expression>, boost::recursive_wrapper<Arglist>> value;
};

}}

#include "asg/Initlist.hpp"
#include "asg/Expression.hpp"
//#include "asg/Constructcall.hpp"
#include "asg/Arglist.hpp"

#endif //ICE_SCRIPT_ASG_VARIABLE_HPP