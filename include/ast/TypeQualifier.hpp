#ifndef ICE_SCRIPT_AST_TYPEQUALIFIER_HPP
#define ICE_SCRIPT_AST_TYPEQUALIFIER_HPP

#include "type/TypeQualifier.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

// enum class TypeQualifier
// {
//     NONE,
//     CONSTANT,
//     VOLATILE,
// };

inline std::string toString(const TypeQualifier::TypeQualifierFlags TypeQualifier)
{
    switch (TypeQualifier)
    {
        case TypeQualifier::NONE: return "NONE";
        case TypeQualifier::CONSTANT: return "CONSTANT";
        case TypeQualifier::VOLATILE: return "VOLATILE";

        default:
            throw InvalidArgumentException("Type qualifier not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const TypeQualifier::TypeQualifierFlags typeQualifier)
{
    os << "(TypeQualifier)[" << toString(typeQualifier) << "]";

    return os;
}

}}

#endif /* ICE_SCRIPT_AST_TYPEQUALIFIER_HPP */
