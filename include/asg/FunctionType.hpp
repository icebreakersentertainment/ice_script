#ifndef ICE_SCRIPT_FUNCTIONTYPE_HPP
#define ICE_SCRIPT_FUNCTIONTYPE_HPP

#include "asg/Type.hpp"

namespace ice_script { namespace asg {

class FunctionType : public Type
{
public:
    FunctionType() : Type(Type::TypeId::FUNCTION)
    {

    }

    const std::vector<std::shared_ptr<Type>>& parameters() const
    {
        return parameters_;
    }

    void setParameters(std::vector<std::shared_ptr<Type>> parameters)
    {
        parameters_ = std::move(parameters);
    }

    const std::shared_ptr<Type>& returnType() const
    {
        return returnType_;
    }

    void setReturnType(std::shared_ptr<Type> returnType)
    {
        returnType_ = std::move(returnType);
    }

protected:
    std::vector<std::shared_ptr<Type>> parameters_;
    std::shared_ptr<Type> returnType_;

};

}}

#endif //ICE_SCRIPT_FUNCTIONTYPE_HPP
