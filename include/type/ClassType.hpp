#ifndef ICE_SCRIPT_CLASSTYPE_HPP
#define ICE_SCRIPT_CLASSTYPE_HPP

#include <vector>
#include <memory>

#include "type/Types.hpp"
#include "type/ConstructorTypes.hpp"
#include "type/FunctionType.hpp"
#include "type/OperatorTypeId.hpp"

namespace ice_script
{

class ClassType : public Type
{
public:
    ClassType() : Type(Type::TypeId::CLASS)
    {

    }
    
    ClassType(const ClassType& other) : Type(other)
    {
        memberVariables_ = other.memberVariables_;
        constructors_ = other.constructors_;
    }

    friend std::ostream& operator<<(std::ostream& os, const ClassType& classType);

    Types& memberVariables()
    {
        return memberVariables_;
    }

    const Types& memberVariables() const
    {
        return memberVariables_;
    }

    ConstructorTypes& constructors()
    {
        return constructors_;
    }

    const ConstructorTypes& constructors() const
    {
        return constructors_;
    }

protected:
    // std::vector<std::shared_ptr<Type>> memberVariables_;
    Types memberVariables_;
    // std::vector<std::shared_ptr<FunctionType>> constructors_;
    ConstructorTypes constructors_;

};

std::string toString(const ClassType& classType);

}

#endif //ICE_SCRIPT_CLASSTYPE_HPP
