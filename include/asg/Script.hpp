#ifndef ICE_SCRIPT_ASG_SCRIPT_HPP
#define ICE_SCRIPT_ASG_SCRIPT_HPP

#include <string>

#include "asg/Import.hpp"
#include "asg/Enumeration.hpp"
#include "asg/Typedefinition.hpp"
#include "asg/Class.hpp"
#include "asg/Mixin.hpp"
#include "asg/Interface.hpp"
#include "asg/Functiondefinition.hpp"
#include "asg/Virtualproperatorerty.hpp"
#include "asg/Variable.hpp"
#include "asg/Function.hpp"
#include "asg/Namespace.hpp"
#include "asg/Statblock.hpp"
#include "asg/Statement.hpp"
#include "asg/Initlist.hpp"
#include "asg/Expression.hpp"
#include "asg/Constructcall.hpp"
#include "asg/Expressionterm.hpp"
#include "asg/Expressionvalue.hpp"
#include "asg/Functioncall.hpp"
#include "asg/Variableaccess.hpp"
#include "asg/Cast.hpp"
#include "asg/Literal.hpp"
#include "asg/Number.hpp"
#include "asg/String.hpp"
#include "asg/Bits.hpp"
#include "asg/Assign.hpp"
#include "asg/Condition.hpp"
#include "asg/Lambda.hpp"
#include "asg/Return.hpp"
#include "asg/Interfacemethod.hpp"

namespace ice_script { namespace asg {

using Node1 = boost::variant<
//        std::string,
//        Import,
//        Enumeration,
//        Typedefinition,
//        Class,
//        Mixin,
//        Interface,
//        Functiondefinition,
//        Virtualproperatorerty,
//        Variable,
//        Function,
//        Namespace,
//        Statblock,
//        Statement,
//        Initlist,
//        Expression,
//        Constructcall,
//        Expressionterm,
//        Expressionvalue,
//        Functioncall,
//        Variableaccess,
//        Cast,
//        Literal,
//        Number,
//        String,
//        Bits,
//        Assign,
//        Condition,
//        Lambda,
//        Return,
//        Interfacemethod

        std::string,
        Arglist,
        Assign,
        Assignoperator,
        Bitoperator,
        Bits,
        Break,
        Case,
        Cast,
        Class,
        Comparisonoperator,
        Condition,
        Constructcall,
        Continue,
        Datatype,
        Dowhile,
        Enumeration,
        Expression,
        Expressionoperatorerty,
        Expressionpostoperator,
        Expressionpreoperator,
        Expressionstat,
        Expressionterm,
        Expressionvalue,
        For,
        Function,
        Functionattribute,
        Functioncall,
        Functiondefinition,
        Identifier,
        If
>;

using Node = boost::variant<
        Import,
        Initlist,
        Interface,
        Interfacemethod,
        Lambda,
        Literal,
        Logicoperator,
        Mathoperator,
        Mixin,
        Namespace,
        Number,
        Parameterlist,
        Primativetype,
//        PrimitiveType,
        Return,
        Scoperatore,
        Statblock,
        Statement,
        String,
        Switch,
        Try,
        Typedefinition,
        Typemodifier,
        Variable,
        Variableaccess,
        Virtualproperatorerty,
        While,
        Type,
        Node1
>;

struct Script
{
    std::vector<Node> nodes;
};

}}

#endif //ICE_SCRIPT_ASG_SCRIPT_HPP