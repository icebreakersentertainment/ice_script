#ifndef ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP
#define ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP

#include <string>

#include "ast/PrimitiveType.hpp"
#include "asg/Type.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace analyzer {

inline std::string toName(const std::string& string)
{
    return string;
}

inline std::string toString(const asg::Type::TypeId typeId)
{
    switch (typeId)
    {
        case asg::Type::TypeId::INTEGER8: return "int8";
        case asg::Type::TypeId::INTEGER16: return "int16";
        case asg::Type::TypeId::INTEGER32: return "int32";
        case asg::Type::TypeId::INTEGER: return "int";
        case asg::Type::TypeId::INTEGER64: return "int64";
        case asg::Type::TypeId::UINTEGER8: return "uint8";
        case asg::Type::TypeId::UINTEGER16: return "uint16";
        case asg::Type::TypeId::UINTEGER32: return "uint32";
        case asg::Type::TypeId::UINTEGER: return "uint";
        case asg::Type::TypeId::UINTEGER64: return "uint64";
        case asg::Type::TypeId::FLOAT: return "float";
        case asg::Type::TypeId::DOUBLE: return "double";
    }

    throw InvalidArgumentException("");
}

inline std::string toString(const ast::PrimitiveType primitiveType)
{
    return toString(asg::PrimitiveType::toTypeId(primitiveType));
}

}}

#endif //ICE_SCRIPT_ANALYZER_ANALYZERUTILITIES_HPP
