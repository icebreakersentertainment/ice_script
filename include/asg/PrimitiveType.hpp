#ifndef ICE_SCRIPT_ASG_PRIMITIVETYPE_HPP
#define ICE_SCRIPT_ASG_PRIMITIVETYPE_HPP

#include "ast/PrimitiveType.hpp"

#include "asg/Type.hpp"

#include "detail/Format.hpp"
#include "exceptions/RuntimeException.hpp"

namespace ice_script { namespace asg {

class PrimitiveType : public Type
{
public:
    PrimitiveType(const ast::PrimitiveType primitiveType) : Type(toTypeId(primitiveType)), type_(primitiveType)
    {

    }

    static TypeId toTypeId(const ast::PrimitiveType primitiveType)
    {
        switch (primitiveType)
        {
            case ast::PrimitiveType::INT8: return TypeId::INTEGER8;
            case ast::PrimitiveType::INT16: return TypeId::INTEGER16;
            case ast::PrimitiveType::INT32: return TypeId::INTEGER32;
            case ast::PrimitiveType::INT: return TypeId::INTEGER;
            case ast::PrimitiveType::INT64: return TypeId::INTEGER64;
            case ast::PrimitiveType::UINT8: return TypeId::UINTEGER8;
            case ast::PrimitiveType::UINT16: return TypeId::UINTEGER16;
            case ast::PrimitiveType::UINT32: return TypeId::UINTEGER32;
            case ast::PrimitiveType::UINT: return TypeId::UINTEGER;
            case ast::PrimitiveType::UINT64: return TypeId::UINTEGER64;
            case ast::PrimitiveType::FLOAT: return TypeId::FLOAT;
            case ast::PrimitiveType::DOUBLE: return TypeId::DOUBLE;

            default:
                throw RuntimeException(detail::format("Unknown primitive type '%s'", static_cast<uint32_t>(primitiveType)));
        }
    }

protected:
    ast::PrimitiveType type_;

//    Scope scope;
//    DataType dataType;
//    TypeNodeTemplates templates;
//    std::vector<
//            boost::variant<std::string, boost::tuple<std::string, boost::optional<std::string>>>
//    > bracketsOrAtOptionalConst;
};

}}

#endif //ICE_SCRIPT_ASG_PRIMITIVETYPE_HPP
