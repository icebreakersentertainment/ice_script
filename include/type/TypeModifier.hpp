#ifndef ICE_SCRIPT_TYPE_TYPEMODIFIER_HPP
#define ICE_SCRIPT_TYPE_TYPEMODIFIER_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script {

enum class TypeModifier : uint32_t
{
	NONE = 0,
	VALUE,
	REFERENCE,
	POINTER,
	SMART_POINTER,
};

inline std::string toString(const TypeModifier typeModifier)
{
    switch (typeModifier)
    {
        case TypeModifier::NONE: return "NONE";
        case TypeModifier::VALUE: return "VALUE";
        case TypeModifier::REFERENCE: return "REFERENCE";
        case TypeModifier::POINTER: return "POINTER";
        case TypeModifier::SMART_POINTER: return "SMART_POINTER";

        default:
            throw InvalidArgumentException("Type modifier not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const TypeModifier typeModifier)
{
    os << "(TypeModifier)[" << toString(typeModifier) << "]";

    return os;
}

}

#endif /* ICE_SCRIPT_TYPE_TYPEMODIFIER_HPP */
