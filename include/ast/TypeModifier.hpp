#ifndef ICE_SCRIPT_AST_TYPEMODIFIER_HPP
#define ICE_SCRIPT_AST_TYPEMODIFIER_HPP

#include "type/TypeModifier.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

// enum class TypeModifier
// {
//     NONE,
//     VALUE,
//     REFERENCE,
//     POINTER,
//     SMART_POINTER,
// };

// inline std::string toString(const TypeModifier typeModifier)
// {
//     switch (typeModifier)
//     {
//         case TypeModifier::NONE: return "NONE";
//         case TypeModifier::VALUE: return "VALUE";
//         case TypeModifier::REFERENCE: return "REFERENCE";
//         case TypeModifier::POINTER: return "POINTER";
//         case TypeModifier::SMART_POINTER: return "SMART_POINTER";

//         default:
//             throw InvalidArgumentException("Type modifier not valid.");
//     }
// }

// inline std::ostream& operator<<(std::ostream& os, const TypeModifier typeModifier)
// {
//     os << "(TypeModifier)[" << toString(typeModifier) << "]";

//     return os;
// }

}}

#endif /* ICE_SCRIPT_AST_TYPEMODIFIER_HPP */
