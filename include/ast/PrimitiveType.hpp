#ifndef ICE_SCRIPT_PRIMITIVETYPE_HPP
#define ICE_SCRIPT_PRIMITIVETYPE_HPP

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace ast {

enum class PrimitiveType
{
    UNKNOWN,
    VOID_T,
    INT,
    INT8,
    INT16,
    INT32,
    INT64,
    UINT,
    UINT8,
    UINT16,
    UINT32,
    UINT64,
    FLOAT,
    DOUBLE,
    BOOLEAN

};

inline std::string toString(const PrimitiveType primitiveType)
{
    switch (primitiveType)
    {
        case PrimitiveType::UNKNOWN: return "UNKNOWN";
        case PrimitiveType::VOID_T: return "VOID_T";
        case PrimitiveType::BOOLEAN: return "BOOLEAN";
        case PrimitiveType::INT8: return "INT8";
        case PrimitiveType::INT16: return "INT16";
        case PrimitiveType::INT32: return "INT32";
        case PrimitiveType::INT: return "INT";
        case PrimitiveType::INT64: return "INT64";
        case PrimitiveType::UINT8: return "UINT8";
        case PrimitiveType::UINT16: return "UINT16";
        case PrimitiveType::UINT32: return "UINT32";
        case PrimitiveType::UINT: return "UINT";
        case PrimitiveType::UINT64: return "UINT64";
        case PrimitiveType::FLOAT: return "FLOAT";
        case PrimitiveType::DOUBLE: return "DOUBLE";

        default:
            throw InvalidArgumentException("Primitive type not valid.");
    }
}

inline std::ostream& operator<<(std::ostream& os, const PrimitiveType primitiveType)
{
    os << "(" << boost::typeindex::type_id<PrimitiveType>().pretty_name() << ")[" << toString(primitiveType) << "]";

    return os;
}

}}

#endif //ICE_SCRIPT_PRIMITIVETYPE_HPP
