#ifndef ICE_SCRIPT_ASG_CLASS_HPP
#define ICE_SCRIPT_ASG_CLASS_HPP

#include <string>

//#include "asg/Identifier.hpp"
#include "asg/LocationInfo.hpp"

#include "type/ClassType.hpp"
#include "symbol/ClassSymbol.hpp"

namespace ice_script { namespace asg {

struct Virtualproperatorerty;
struct Function;
struct Variable;
struct Functiondefinition;

// using VariantVirtualPropertyFunctionVariableFunctionDefinitionType = boost::variant<
// //            asg::Identifier,
//         boost::recursive_wrapper<Virtualproperatorerty>,
//         boost::recursive_wrapper<Function>,
//         boost::recursive_wrapper<Variable>,
//         boost::recursive_wrapper<Functiondefinition>
// >;

// CLASS         ::= {'shared' | 'abstract' | 'final' | 'external'} 'class' IDENTIFIER (';' | ([':' IDENTIFIER {',' IDENTIFIER}] '{' {VIRTPROP | FUNC | VAR | FUNCDEF} '}'))
struct Class : LocationInfo
{
    std::string name;
    std::shared_ptr<ClassType> type;
    std::shared_ptr<ClassSymbol> symbol;
    std::vector<boost::recursive_wrapper<Virtualproperatorerty>> virtualproperatorerties;
    std::vector<boost::recursive_wrapper<Function>> functions;
    std::vector<boost::recursive_wrapper<Variable>> variables;
    std::vector<boost::recursive_wrapper<Functiondefinition>> functiondefinitions;
    // std::vector<VariantVirtualPropertyFunctionVariableFunctionDefinitionType> virtualPropertyFunctionVariableFunctionDefinitions;
};

}}

#include "asg/Virtualproperatorerty.hpp"
#include "asg/Function.hpp"
#include "asg/Variable.hpp"
#include "asg/Functiondefinition.hpp"

#endif //ICE_SCRIPT_ASG_CLASS_HPP