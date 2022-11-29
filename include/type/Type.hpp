#ifndef ICE_SCRIPT_ASG_TYPE_HPP
#define ICE_SCRIPT_ASG_TYPE_HPP

#include <string>
#include <vector>
#include <memory>

#include "asg/Scoperatore.hpp"
#include "asg/Datatype.hpp"

#include "type/OperatorTypeId.hpp"
#include "type/OperatorTypes.hpp"
#include "type/TypeQualifier.hpp"
#include "type/TypeModifier.hpp"

#include "detail/Format.hpp"
#include "detail/InsertionOperatorUtils.hpp"

namespace ice_script
{

class OperatorType;
class OperatorTypes;

inline std::string toTypeKey(const std::string& name, const uint32_t qualifiers, const TypeModifier modifier)
{
    return ice_script::detail::format(
        "%s%s%s",
        (qualifiers & TypeQualifier::CONSTANT ? "c_" : ""),
        (modifier == TypeModifier::VALUE ? "v_" : (modifier == TypeModifier::REFERENCE ? "r_" : (modifier == TypeModifier::POINTER ? "p_" : ""))),
        name
    );
}

class Type
{
public:
    enum class TypeId
    {
        UNKNOWN = 0,
        VOID_T,
        BOOLEAN,
        INTEGER8,
        INTEGER16,
        INTEGER32,
        INTEGER,
        INTEGER64,
        UINTEGER8,
        UINTEGER16,
        UINTEGER32,
        UINTEGER,
        UINTEGER64,
        FLOAT,
        DOUBLE,

        ARRAY,
        CLASS,
        FUNCTION,
        OPERATOR,
    };

    Type() = default;

    // explicit Type(const TypeId typeId) : typeId_(typeId)
    // {

    // }
    
    // Type(const Type& other)
    // {
    //     typeId_ = other.typeId_;
    //     name_ = other.name_;
    //     operators_ = other.operators_;
    //     qualifiers_ = other.qualifiers_;
    //     modifier_ = other.modifier_;
    // }

    // virtual ~Type() = default;
    
    explicit Type(const TypeId typeId);
    
    Type(const Type& other);

    virtual ~Type();

    Type& operator=(const Type& other);
    Type& operator=(Type&& other);
    
    friend std::ostream& operator<<(std::ostream& os, const Type& type);

    friend std::ostream& operator<<(std::ostream& os, const TypeId typeId);

    TypeId typeId() const
    {
        return typeId_;
    }

    const std::string& name() const
    {
        return name_;
    }

    void setName(std::string name)
    {
        name_ = std::move(name);
    }
    
    const std::string& fullyQualifiedScopeName() const
    {
        return fullyQualifiedScopeName_;
    }

    void setFullyQualifiedScopeName(std::string fullyQualifiedScopeName)
    {
        fullyQualifiedScopeName_ = std::move(fullyQualifiedScopeName);
    }
    
    OperatorTypes& operators()
    {
        return *operators_;
    }

    const OperatorTypes& operators() const
    {
        return *operators_;
    }
    
    uint32_t qualifiers() const
    {
        return qualifiers_;
    }
    
    void setQualifiers(const uint32_t qualifiers)
    {
        qualifiers_ = qualifiers;
        
        key_ = "";
    }
    
    TypeModifier modifier() const
    {
        return modifier_;
    }

    void setModifier(const TypeModifier modifier)
    {
        modifier_ = modifier;
    }

    virtual const std::string& key() const
    {
        // if (!key_.empty()) return key_;
        
        key_ = detail::format(
            "%s%s%s",
            (qualifiers_ & TypeQualifier::CONSTANT ? "c_" : ""),
            (modifier_ == TypeModifier::VALUE ? "v_" : (modifier_ == TypeModifier::REFERENCE ? "r_" : (modifier_ == TypeModifier::POINTER ? "p_" : ""))),
            name_
        );
        
        return key_;
        // return name_;
    }

    virtual bool primitive() const
    {
        return false;
    }

    bool implicitlyConvertibleTo(const std::shared_ptr<Type>& type) const
    {
        return false;
    }

    // std::vector<std::shared_ptr<OperatorType>> findOperators(const OperatorTypeId operatorTypeId);

    // void setOperators(std::vector<std::shared_ptr<OperatorType>> operators);

protected:
    // TYPE          ::= ['const'] SCOPE DATATYPE ['<' TYPE {',' TYPE} '>'] { ('[' ']') | ('@' ['const']) }
    TypeId typeId_;
    std::string name_;
    std::string fullyQualifiedScopeName_;
    mutable std::string key_;
    // std::vector<std::shared_ptr<OperatorType>> operators_;
    std::unique_ptr<OperatorTypes> operators_;
    uint32_t qualifiers_ = ice_script::TypeQualifier::NONE;
    TypeModifier modifier_ = TypeModifier::VALUE;
//    Scope scope;
//    DataType dataType;
//    TypeNodeTemplates templates;
//    std::vector<
//            boost::variant<std::string, boost::tuple<std::string, boost::optional<std::string>>>
//    > bracketsOrAtOptionalConst;
};

std::string toString(const Type& type);
std::string toString(const Type::TypeId typeId);

std::string toTypeKey(const Type& type);

}

#endif //ICE_SCRIPT_ASG_TYPE_HPP