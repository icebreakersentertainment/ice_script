#ifndef ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP
#define ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP

#include <string>

#include "ast/PrimitiveType.hpp"
#include "type/Type.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

inline std::string toName(const std::string& string)
{
    return string;
}

inline std::string toName(const Type::TypeId typeId)
{
    switch (typeId)
    {
        case Type::TypeId::VOID_T: return "void";
        case Type::TypeId::BOOLEAN: return "bool";
        case Type::TypeId::INTEGER8: return "int8";
        case Type::TypeId::INTEGER16: return "int16";
        case Type::TypeId::INTEGER32: return "int32";
        case Type::TypeId::INTEGER: return "int";
        case Type::TypeId::INTEGER64: return "int64";
        case Type::TypeId::UINTEGER8: return "uint8";
        case Type::TypeId::UINTEGER16: return "uint16";
        case Type::TypeId::UINTEGER32: return "uint32";
        case Type::TypeId::UINTEGER: return "uint";
        case Type::TypeId::UINTEGER64: return "uint64";
        case Type::TypeId::FLOAT: return "float";
        case Type::TypeId::DOUBLE: return "double";
    }

    throw InvalidArgumentException("");
}

inline std::string toName(const ast::PrimitiveType primitiveType)
{
    return toName(PrimitiveType::toTypeId(primitiveType));
}

}}}

#endif //ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP
