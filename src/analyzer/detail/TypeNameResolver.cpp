#include "analyzer/detail/TypeNameResolver.hpp"

#include "detail/Assert.hpp"
#include "type/PrimitiveType.hpp"

#include "detail/Format.hpp"

#include "exceptions/InvalidArgumentException.hpp"

namespace ice_script { namespace analyzer { namespace detail {

using namespace ice_script::ast;
using namespace ice_script::asg;

std::string resolveTypeName(const Type::TypeId typeId)
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

std::string resolveTypeName(const ast::PrimitiveType primitiveType)
{
    return resolveTypeName(ice_script::PrimitiveType::toTypeId(primitiveType));
}

std::string resolveTypeName(const ast::IdentifierNode& node)
{
    return node.value;
}

struct DatatypeNodeVariantValueTypeVisitor : public boost::static_visitor<std::string>
{
    std::string operator()(const monostate& node) const
    {
        ICE_SCRIPT_ASSERT(false);
        
        return "";
    }
    
    std::string operator()(const ast::IdentifierNode& node) const
    {
        return node.value;
    }
    
    std::string operator()(const ast::PrimtypeNode& node) const
    {
        return resolveTypeName(node.primitiveType);
    }
    
    std::string operator()(const std::string& node) const
    {
        return "";
    }
};

std::string resolveTypeName(const ast::DatatypeNode& node)
{
    return boost::apply_visitor(DatatypeNodeVariantValueTypeVisitor(), node.value);
}

}}}