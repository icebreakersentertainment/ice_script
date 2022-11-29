#ifndef ICE_SCRIPT_FUNCTIONTYPE_HPP
#define ICE_SCRIPT_FUNCTIONTYPE_HPP

#include <vector>
#include <memory>

#include <boost/algorithm/string.hpp>

#include "type/Type.hpp"

#include "detail/Format.hpp"

namespace ice_script
{

inline std::string toFunctionTypeKey(const std::string& returnTypeKey, const std::string& classTypeKey, const std::vector<std::string>& parameterTypeKeys)
{
    const auto parameters = boost::algorithm::join(parameterTypeKeys, "_");
    
    return ice_script::detail::format(
        "%s_%s_%s%s",
        returnTypeKey,
        "function",
        !classTypeKey.empty() ? classTypeKey + "_" : "",
        parameters
    );
}

class Types;
class FunctionType;

std::string toFunctionTypeKey(const FunctionType& functionType);

class FunctionType : public Type
{
public:
    // FunctionType() : Type(Type::TypeId::FUNCTION)
    // {

    // }
    
    // FunctionType(const FunctionType& other) : Type(other)
    // {
    //     parameters_ = std::make_unique<Types>(other.parameters_);
    //     returnType_ = other.returnType_;
    //     ownerType_ = other.ownerType_;
    //     isMethod_ = other.isMethod_;
    //     isConstructor_ = other.isConstructor_;
    // }
    
    FunctionType();
    
    FunctionType(const FunctionType& other);

    friend std::ostream& operator<<(std::ostream& os, const FunctionType& functionType);

    const std::string& key() const override
    {
        // if (!key_.empty()) return key_;
        
        key_ = toFunctionTypeKey(*this);
        
        return key_;
    }

    Types& parameters()
    {
        return *parameters_;
    }

    const Types& parameters() const
    {
        return *parameters_;
    }

    const std::shared_ptr<Type>& returnType() const
    {
        return returnType_;
    }

    void setReturnType(std::shared_ptr<Type> returnType)
    {
        returnType_ = std::move(returnType);
    }

    const std::shared_ptr<Type>& ownerType() const
    {
        return ownerType_;
    }

    void setOwnerType(std::shared_ptr<Type> ownerType)
    {
        ownerType_ = std::move(ownerType);
    }

    virtual bool isMethod() const
    {
        return isMethod_;
    }

    void setIsMethod(const bool isMethod)
    {
        isMethod_ = isMethod;
    }

    virtual bool isConstructor() const
    {
        return isConstructor_;
    }

    void setIsConstructor(const bool isConstructor)
    {
        isConstructor_ = isConstructor;
    }

protected:
    // std::vector<std::shared_ptr<Type>> parameters_;
    std::unique_ptr<Types> parameters_;
    std::shared_ptr<Type> returnType_;
    std::shared_ptr<Type> ownerType_;
    bool isMethod_ = false;
    bool isConstructor_ = false;

};

std::string toString(const FunctionType& functionType);

// inline std::string toFunctionTypeKey(const FunctionType& functionType)
// {
//     std::vector<std::string> parameters{};
//     for (const auto& parameter : functionType.parameters()) parameters.push_back(parameter->key());
    
//     return toFunctionTypeKey(
//         functionType.returnType()->key(),
//         functionType.ownerType() ? functionType.ownerType()->key() : "",
//         parameters
//     );
// }

}

#include "type/Types.hpp"

#endif //ICE_SCRIPT_FUNCTIONTYPE_HPP
