#ifndef ICE_SCRIPT_ASG_FUNCTION_HPP
#define ICE_SCRIPT_ASG_FUNCTION_HPP

#include <string>

#include "asg/Type.hpp"
#include "asg/Variable.hpp"
//#include "asg/Identifier.hpp"
//#include "asg/Parameterlist.hpp"
//#include "asg/Functionattribute.hpp"

namespace ice_script { namespace asg {

struct Statblock;

// FUNC          ::= {'shared' | 'external'} ['private' | 'protected'] [((TYPE ['&']) | '~')] IDENTIFIER PARAMLIST ['const'] FUNCATTR (';' | STATBLOCK)
struct Function
{
    std::shared_ptr<Type> returnType;
    std::string name;
    std::vector<Variable> parameters;
    boost::recursive_wrapper<Statblock> body;
};

}}

#include "asg/Statblock.hpp"

#endif //ICE_SCRIPT_ASG_FUNCTION_HPP