#ifndef ICE_SCRIPT_TYPE_TYPEQUALIFIER_HPP
#define ICE_SCRIPT_TYPE_TYPEQUALIFIER_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace TypeQualifier {
    
enum TypeQualifierFlags : uint32_t
{
	NONE 	    = 1 << 0,
	CONSTANT 	= 1 << 1,
	VOLATILE 	= 1 << 2,
};

inline std::string toString(const TypeQualifierFlags typeQualifierFlags)
{
    switch (typeQualifierFlags)
    {
        case TypeQualifierFlags::NONE: return "NONE";
        case TypeQualifierFlags::CONSTANT: return "CONSTANT";
        case TypeQualifierFlags::VOLATILE: return "VOLATILE";
        
        default:
            throw InvalidArgumentException("Type qualifier flags not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const TypeQualifierFlags typeQualifierFlags)
{
    os << "(TypeQualifierFlags)[" << toString(typeQualifierFlags) << "]";

    return os;
}

}}

#endif /* ICE_SCRIPT_TYPE_TYPEQUALIFIER_HPP */
