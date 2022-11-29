#ifndef ICE_SCRIPT_OPERATORTYPEID_HPP
#define ICE_SCRIPT_OPERATORTYPEID_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script
{

enum class OperatorTypeId
{
    UNKNOWN = 0,
    VOID_T,

    // Prefixed Unary Operators
    PREFIX_NEGATE,
    PREFIX_COMPLIMENT,
    PREFIX_INCREMENT,
    PREFIX_DECREMENT,
    
    // Postfix Unary Operators
    POSTFIX_INCREMENT,
    POSTFIX_DECREMENT,
    
    // Comparison Operators
    EQUALS,
    NOT_EQUALS,
    LESS_THAN,
    LESS_THAN_OR_EQUALS,
    GREATER_THAN,
    GREATER_THAN_OR_EQUALS,
    IS,
    IS_NOT,

    // Assignment Operators
    ASSIGN_EQUAL,
    ASSIGN_ADD,
    ASSIGN_SUBTRACT,
    ASSIGN_MULTIPLY,
    ASSIGN_DIVIDE,
    ASSIGN_MODULOS,
    ASSIGN_EXPONENT,
    ASSIGN_AND,
    ASSIGN_OR,
    ASSIGN_XOR,
    ASSIGN_LEFT_SHIFT,
    ASSIGN_RIGHT_SHIFT,
    ASSIGN_ARITHMETIC_RIGHT_SHIFT,

    // Bitwise Operators
    BITWISE_COMPLEMENT,
    BITWISE_AND,
    BITWISE_OR,
    BITWISE_XOR,
    BITWISE_LEFT_SHIFT,
    BITWISE_RIGHT_SHIFT,
    BITWISE_ARITHMETIC_RIGHT_SHIFT,

    // Math Operators
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULOS,
    EXPONENT,

    // Logic Operators
    AND,
    OR,
    XOR,
    NOT,
    
    // Index operators
    INDEX,
    
    // Functor operator
    CALL,
    
    // Type conversion operators
    EXPLICIT_CONVERSION,
    IMPLICIT_CONVERSION,
};

inline std::string toString(const OperatorTypeId operatorTypeId)
{
    switch (operatorTypeId)
    {
        case OperatorTypeId::UNKNOWN: return "UNKNOWN";
        case OperatorTypeId::VOID_T: return "VOID_T";
        
        // Prefixed Unary Operators
        case OperatorTypeId::PREFIX_NEGATE: return "PREFIX_NEGATE";
        case OperatorTypeId::PREFIX_COMPLIMENT: return "PREFIX_COMPLIMENT";
        case OperatorTypeId::PREFIX_INCREMENT: return "PREFIX_INCREMENT";
        case OperatorTypeId::PREFIX_DECREMENT: return "PREFIX_DECREMENT";
        
        // Postfix Unary Operators
        case OperatorTypeId::POSTFIX_INCREMENT: return "POSTFIX_INCREMENT";
        case OperatorTypeId::POSTFIX_DECREMENT: return "POSTFIX_DECREMENT";
        
        // Comparison Operators
        case OperatorTypeId::EQUALS: return "EQUALS";
        case OperatorTypeId::NOT_EQUALS: return "NOT_EQUALS";
        case OperatorTypeId::LESS_THAN: return "LESS_THAN";
        case OperatorTypeId::LESS_THAN_OR_EQUALS: return "LESS_THAN_OR_EQUALS";
        case OperatorTypeId::GREATER_THAN: return "GREATER_THAN";
        case OperatorTypeId::GREATER_THAN_OR_EQUALS: return "GREATER_THAN_OR_EQUALS";
        case OperatorTypeId::IS: return "IS";
        case OperatorTypeId::IS_NOT: return "IS_NOT";

        // Assignment Operators
        case OperatorTypeId::ASSIGN_EQUAL: return "ASSIGN_EQUAL";
        case OperatorTypeId::ASSIGN_ADD: return "ASSIGN_ADD";
        case OperatorTypeId::ASSIGN_SUBTRACT: return "ASSIGN_SUBTRACT";
        case OperatorTypeId::ASSIGN_MULTIPLY: return "ASSIGN_MULTIPLY";
        case OperatorTypeId::ASSIGN_DIVIDE: return "ASSIGN_DIVIDE";
        case OperatorTypeId::ASSIGN_MODULOS: return "ASSIGN_MODULOS";
        case OperatorTypeId::ASSIGN_EXPONENT: return "ASSIGN_EXPONENT";
        case OperatorTypeId::ASSIGN_AND: return "ASSIGN_AND";
        case OperatorTypeId::ASSIGN_OR: return "ASSIGN_OR";
        case OperatorTypeId::ASSIGN_XOR: return "ASSIGN_XOR";
        case OperatorTypeId::ASSIGN_LEFT_SHIFT: return "ASSIGN_LEFT_SHIFT";
        case OperatorTypeId::ASSIGN_RIGHT_SHIFT: return "ASSIGN_RIGHT_SHIFT";
        case OperatorTypeId::ASSIGN_ARITHMETIC_RIGHT_SHIFT: return "ASSIGN_ARITHMETIC_RIGHT_SHIFT";

        // Bitwise Operators
        case OperatorTypeId::BITWISE_COMPLEMENT: return "BITWISE_COMPLEMENT";
        case OperatorTypeId::BITWISE_AND: return "BITWISE_AND";
        case OperatorTypeId::BITWISE_OR: return "BITWISE_OR";
        case OperatorTypeId::BITWISE_XOR: return "BITWISE_XOR";
        case OperatorTypeId::BITWISE_LEFT_SHIFT: return "BITWISE_LEFT_SHIFT";
        case OperatorTypeId::BITWISE_RIGHT_SHIFT: return "BITWISE_RIGHT_SHIFT";
        case OperatorTypeId::BITWISE_ARITHMETIC_RIGHT_SHIFT: return "BITWISE_ARITHMETIC_RIGHT_SHIFT";

        // Math Operators
        case OperatorTypeId::ADD: return "ADD";
        case OperatorTypeId::SUBTRACT: return "SUBTRACT";
        case OperatorTypeId::MULTIPLY: return "MULTIPLY";
        case OperatorTypeId::DIVIDE: return "DIVIDE";
        case OperatorTypeId::MODULOS: return "MODULOS";
        case OperatorTypeId::EXPONENT: return "EXPONENT";

        // Logic Operators
        case OperatorTypeId::AND: return "AND";
        case OperatorTypeId::OR: return "OR";
        case OperatorTypeId::XOR: return "XOR";
        case OperatorTypeId::NOT: return "NOT";
        
        // Index operators
        case OperatorTypeId::INDEX: return "INDEX";
        
        // Functor operator
        case OperatorTypeId::CALL: return "CALL";
        
        // Type conversion operators
        case OperatorTypeId::EXPLICIT_CONVERSION: return "EXPLICIT_CONVERSION";
        case OperatorTypeId::IMPLICIT_CONVERSION: return "IMPLICIT_CONVERSION";

        default:
            throw InvalidArgumentException("Operator type id not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const OperatorTypeId operatorTypeId)
{
    os << "(OperatorTypeId)[" << toString(operatorTypeId) << "]";

    return os;
}

}

#endif //ICE_SCRIPT_OPERATORTYPEID_HPP
